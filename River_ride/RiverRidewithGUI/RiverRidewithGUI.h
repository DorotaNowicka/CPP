#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RiverRidewithGUI.h"

class RiverRidewithGUI : public QMainWindow
{
	Q_OBJECT

public:
	RiverRidewithGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::RiverRidewithGUIClass ui;
};
