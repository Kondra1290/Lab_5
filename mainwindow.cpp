#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    toolBar = new QToolBar("Tool Bar", this);
    selectText = new QPushButton("Text", toolBar);
    selectRect = new QPushButton("Rectangle", toolBar);
    selectEllipse = new QPushButton("Ellipse", toolBar);
    selectLine = new QPushButton("Line", toolBar);

    toolBar->addWidget(selectText);
    toolBar->addWidget(selectRect);
    toolBar->addWidget(selectEllipse);
    toolBar->addWidget(selectLine);

    addToolBar(toolBar);

    colors = new QToolBar("Colors", this);
    green = new QPushButton("Green", colors);
    red = new QPushButton("Red", colors);
    blue = new QPushButton("Blue", colors);
    white = new QPushButton("White", colors);

    colors->addWidget(green);
    colors->addWidget(red);
    colors->addWidget(blue);
    colors->addWidget(white);
    addToolBar(colors);

    text = new QToolBar("Tool Bar", this);
    line = new QLineEdit("", text);
    change = new QPushButton("Изменить", text);
    toolBar->addWidget(line);
    toolBar->addWidget(change);
    addToolBar(text);

    graphics = new MyGraphicsView();
    ui->gridLayout->addWidget(graphics);
    setCentralWidget(graphics);

    connect(selectText,    &QPushButton::clicked, graphics, [=](){ graphics->addText(); });
    connect(selectRect,    &QPushButton::clicked, graphics, [=](){ graphics->addRect(); });
    connect(selectEllipse, &QPushButton::clicked, graphics, [=](){ graphics->addEllipse(); });
    connect(selectLine,    &QPushButton::clicked, graphics, [=](){ graphics->addLine(); });

    connect(green,    &QPushButton::clicked, graphics, [=](){ graphics->paintGreen(); });
    connect(blue, &QPushButton::clicked, graphics, [=](){ graphics->paintBlue(); });
    connect(red,    &QPushButton::clicked, graphics, [=](){ graphics->paintRed(); });
    connect(white,    &QPushButton::clicked, graphics, [=](){ graphics->paintWhite(); });

    connect(change,    &QPushButton::clicked, graphics, [=](){ graphics->changeText(line->text()); });
}

MainWindow::~MainWindow()
{
    delete toolBar;
    delete selectText;
    delete selectRect;
    delete selectEllipse;
    delete selectLine;
    delete graphics;

    delete  colors;
    delete  green;
    delete  red;
    delete  blue;
    delete  white;

    delete  text;
    delete  line;
    delete  change;
    delete ui;
}

