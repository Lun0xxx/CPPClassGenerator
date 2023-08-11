//
// Created by Lun0xxx on 11/08/2023.
//

#include "../headers/GeneratedWindow.hpp"
#include <QWidget>
#include <QTextEdit>

/**
 * FR : Fonction permettant de générer la fenêtre avec le code de la classe
 * EN : Function for generating the window with the class code
 * @param parent
*/
GeneratedWindow::GeneratedWindow(QWidget *parent) {
    setFixedSize(350, 500);

    m_generatedCode = new QTextEdit;
    m_generatedCode->setFont(QFont("Courier", 10));
    m_generatedCode->setReadOnly(true);

    m_quitButton = new QPushButton("Fermer", this);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_generatedCode);
    m_mainLayout->addWidget(m_quitButton);

    setLayout(m_mainLayout);

    connect(m_quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

/**
 * FR : Fonction représentant le destructeur
 * EN : Function representing the destructor
*/
GeneratedWindow::~GeneratedWindow() {
    delete m_generatedCode;
    delete m_quitButton;
    delete m_mainLayout;
}

/**
 * FR : Fonction permettant de récupérer l'objet QTextEdit de la fenêtre générée
 * EN : Function for retrieving the QTextEdit object for the generated window
 * @return
*/
QTextEdit& GeneratedWindow::getWindowCode() {
    return *m_generatedCode;
}