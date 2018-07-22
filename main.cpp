#include "scenemodifier.h"

#include <QGuiApplication>

#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcameralens.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtGui/QScreen>

#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DExtras/qforwardrenderer.h>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DRender/QObjectPicker>
#include <Qt3DRender/QPickEvent>
#include <QRadioButton>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
	view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
	QWidget *container = QWidget::createWindowContainer(view);
	QSize screenSize = view->screen()->size();
	container->setMinimumSize(QSize(200, 100));
	container->setMaximumSize(screenSize);

	QWidget *widget = new QWidget;
	QHBoxLayout *hLayout = new QHBoxLayout(widget);
	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->setAlignment(Qt::AlignTop);
	hLayout->addWidget(container, 1);
	hLayout->addLayout(vLayout);

	widget->setWindowTitle(QStringLiteral("Basic shapes"));

	Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
	view->registerAspect(input);

	// Root entity
	Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

	// Camera
	Qt3DRender::QCamera *cameraEntity = view->camera();

	cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
	cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
	cameraEntity->setUpVector(QVector3D(0, 1, 0));
	cameraEntity->setViewCenter(QVector3D(0, 0, 0));

	Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
	Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
	light->setColor("white");
	light->setIntensity(1);
	lightEntity->addComponent(light);
	Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
	lightTransform->setTranslation(cameraEntity->position());
	lightEntity->addComponent(lightTransform);

	// For camera controls
	Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
	camController->setCamera(cameraEntity);

	// Scenemodifier
	SceneModifier *modifier = new SceneModifier(rootEntity);

	// Set root object of the scene
	view->setRootEntity(rootEntity);

	// Create control widgets
	QCommandLinkButton *info = new QCommandLinkButton();
	info->setText(QStringLiteral("Qt3D ready-made meshes"));
	info->setDescription(QString::fromLatin1("Qt3D provides several ready-made meshes, like torus, cylinder, cone, "
		"cube, plane and sphere."));
	info->setIconSize(QSize(0, 0));

	QCheckBox *torusCB = new QCheckBox(widget);
	torusCB->setChecked(true);
	torusCB->setText(QStringLiteral("Torus"));

	QCheckBox *coneCB = new QCheckBox(widget);
	coneCB->setChecked(true);
	coneCB->setText(QStringLiteral("Cone"));

	QCheckBox *cylinderCB = new QCheckBox(widget);
	cylinderCB->setChecked(true);
	cylinderCB->setText(QStringLiteral("Cylinder"));

	QCheckBox *cuboidCB = new QCheckBox(widget);
	cuboidCB->setChecked(true);
	cuboidCB->setText(QStringLiteral("Cuboid"));

	QCheckBox *planeCB = new QCheckBox(widget);
	planeCB->setChecked(true);
	planeCB->setText(QStringLiteral("Plane"));

	QCheckBox *sphereCB = new QCheckBox(widget);
	sphereCB->setChecked(true);
	sphereCB->setText(QStringLiteral("Sphere"));

	QPushButton *zoomin = new QPushButton(widget);
	zoomin->setText(QStringLiteral("ZoomIn"));
	QPushButton *zoomout = new QPushButton(widget);
	zoomout->setText(QStringLiteral("ZoomOut"));

	QPushButton *up = new QPushButton(widget);
	up->setText(QStringLiteral("Up"));
	QPushButton *down = new QPushButton(widget);
	down->setText(QStringLiteral("Down"));

	QPushButton *left = new QPushButton(widget);
	left->setText(QStringLiteral("Left"));
	QPushButton *right = new QPushButton(widget);
	right->setText(QStringLiteral("Right"));

	QRadioButton *red = new QRadioButton(widget);
	red->setText(QStringLiteral("Red"));
	QRadioButton *yellow = new QRadioButton(widget);
	yellow->setText(QStringLiteral("Yellow"));
	QRadioButton *blue = new QRadioButton(widget);
	blue->setText(QStringLiteral("Blue"));


	//QPushButton *leftrot = new QPushButton(widget);
	//leftrot->setText(QStringLiteral("LeftRotate"));
	//QPushButton *rightrot = new QPushButton(widget);
	//rightrot->setText(QStringLiteral("RightRotate"));

	vLayout->addWidget(info);
	vLayout->addWidget(torusCB);
	vLayout->addWidget(coneCB);
	vLayout->addWidget(cylinderCB);
	vLayout->addWidget(cuboidCB);
	vLayout->addWidget(planeCB);
	vLayout->addWidget(sphereCB);
	vLayout->addWidget(zoomin);
	vLayout->addWidget(zoomout);
	vLayout->addWidget(up);
	vLayout->addWidget(down);
	vLayout->addWidget(left);
	vLayout->addWidget(right);
	//vLayout->addWidget(leftrot);
	//vLayout->addWidget(rightrot);

	vLayout->addWidget(red);
	vLayout->addWidget(yellow);
	vLayout->addWidget(blue);



	QObject::connect(torusCB, &QCheckBox::stateChanged,
		modifier, &SceneModifier::enableTorus);
	QObject::connect(coneCB, &QCheckBox::stateChanged,
		modifier, &SceneModifier::enableCone);
	QObject::connect(cylinderCB, &QCheckBox::stateChanged,
		modifier, &SceneModifier::enableCylinder);
	QObject::connect(cuboidCB, &QCheckBox::stateChanged,
		modifier, &SceneModifier::enableCuboid);
	QObject::connect(planeCB, &QCheckBox::stateChanged,
		modifier, &SceneModifier::enablePlane);
	QObject::connect(sphereCB, &QCheckBox::stateChanged,
		modifier, &SceneModifier::enableSphere);

	QObject::connect(zoomin, &QPushButton::clicked,
		modifier, &SceneModifier::zoomin);
	QObject::connect(zoomout, &QPushButton::clicked,
		modifier,&SceneModifier::zoomout);

	QObject::connect(up, &QPushButton::clicked,
		modifier, &SceneModifier::up);
	QObject::connect(down, &QPushButton::clicked,
		modifier, &SceneModifier::down);
	QObject::connect(left, &QPushButton::clicked,
		modifier, &SceneModifier::left);
	QObject::connect(right, &QPushButton::clicked,
		modifier, &SceneModifier::right);

	QObject::connect(red, &QPushButton::clicked,
		modifier, &SceneModifier::red);
	QObject::connect(yellow, &QPushButton::clicked,
		modifier, &SceneModifier::yellow);
	QObject::connect(blue, &QPushButton::clicked,
		modifier, &SceneModifier::blue);

	/*QObject::connect(leftrot, &QPushButton::clicked,
		modifier, &SceneModifier::leftrot);
	QObject::connect(rightrot, &QPushButton::clicked,
		modifier, &SceneModifier::rightrot);
	///

	/*Qt3DRender::QObjectPicker *picker = new Qt3DRender::QObjectPicker(m_sphereEntity);
	QObject::connect(picker, &(Qt3DRender::QObjectPicker::clicked),
		modifier, &SceneModifier::right);*/

	torusCB->setChecked(true);
	coneCB->setChecked(true);
	cylinderCB->setChecked(true);
	cuboidCB->setChecked(true);
	planeCB->setChecked(true);
	sphereCB->setChecked(true);
	
	// Show window
	widget->show();
	widget->resize(1200, 800);

	return app.exec();
}
