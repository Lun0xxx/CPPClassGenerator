//
// Created by Lun0xxx on 11/08/2023.
//

#ifndef LEARNINGQT_GENERATEDWINDOW_HPP
#define LEARNINGQT_GENERATEDWINDOW_HPP

#include <QWidget>
#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>

class GeneratedWindow : public QDialog {
public:
    GeneratedWindow(QWidget *parent = 0);
    ~GeneratedWindow();
    QTextEdit& getWindowCode();

private:
    QTextEdit *m_generatedCode;

    QPushButton *m_quitButton;

    QVBoxLayout *m_mainLayout;
};

#endif //LEARNINGQT_GENERATEDWINDOW_HPP