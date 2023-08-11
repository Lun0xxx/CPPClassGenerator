//
// Created by Lun0xxx on 11/08/2023.
//

#ifndef LEARNINGQT_MAINWINDOW_HPP
#define LEARNINGQT_MAINWINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>

class MainWindow : public QWidget {
Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

public slots:
    void changeCommentsState();
    void generate();

private:
    QHBoxLayout *m_buttons;

    QVBoxLayout *m_mainWindowLayout;
    QVBoxLayout *m_optionsLayout;

    QLineEdit *m_className;
    QLineEdit *m_parentClassName;
    QLineEdit *m_author;

    QDateEdit *m_creationDate;

    QTextEdit *m_classRole;

    QFormLayout *m_classDefinitionLayout;
    QFormLayout *m_commentairesLayout;

    QPushButton *m_genererButton;
    QPushButton *m_quitButton;

    QCheckBox *m_protectHeader;
    QCheckBox *m_generateDefaultConstructor;
    QCheckBox *m_generateDestructor;
    QCheckBox *m_addComments;

    QFrame *m_classDefinitionFrame;
    QFrame *m_optionsFrame;
    QFrame *m_commentairesFrame;

    QLabel *m_classDefinitionLabel;
    QLabel *m_optionsLabel;
};

#endif //LEARNINGQT_MAINWINDOW_HPP