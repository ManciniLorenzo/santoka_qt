#include <memory>

#include "pages/boatinfowindow.h"
#include "ui_boatinfowindow.h"

#include "widgets/hp_motordesign.h"

BoatInfoWindow::BoatInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoatInfoWindow)
{
    ui->setupUi(this);
}



BoatInfoWindow::~BoatInfoWindow()
{
    delete ui;
}

void BoatInfoWindow::connectInformations(
        PASSSHARED_NONULL (battery_filter, _battery),
        PASSSHARED_NONULL (command_filter, _command),
        PASSSHARED_NONULL (generalinfo_filter, _generalinfo),
        PASSSHARED_NONULL (motor_filter, _motor))
{
    battery = _battery;
    command = _command;
    generalinfo = _generalinfo;
    motor = _motor;

    // Create design
    batterydesign = std::make_shared<hp_batterydesign>(battery, nullptr);
    motordesign = std::make_shared<hp_motordesign>(nullptr);
    generalinfodesign = std::make_shared<hp_generalinfo>(nullptr);

    ui->horizontalLayout->addWidget(batterydesign.get());
    ui->horizontalLayout->addWidget(motordesign.get());
    ui->horizontalLayout->addWidget(generalinfodesign.get());

    // Connect informations
    //connect(battery.get(), SIGNAL(new_bat_SOC(uint8_t)), this, SLOT(setSOC(uint8_t)));
}

void BoatInfoWindow::setSOC(uint8_t newval){

}

void BoatInfoWindow::on_pushButton_clicked()
{
    //disconnect(battery.get(), SIGNAL(new_bat_SOC(uint8_t)), this, SLOT(setSOC(uint8_t)));
    this->close();
}
