//
// Created by Lun0xxx on 11/08/2023.
//

#include "../headers/MainWindow.hpp"
#include "../headers/GeneratedWindow.hpp"
#include <QSize>
#include <QCheckBox>
#include <QApplication>
#include <QMessageBox>

/**
 * FR : Fonction permettant de générer la fenêtre principale du programme
 * EN : Function for generating the main program window
*/
MainWindow::MainWindow() {
    setWindowTitle("C++ Class Generator");

    m_genererButton = new QPushButton("Générer !", this);
    m_genererButton->setFixedSize(80, 30);
    m_quitButton = new QPushButton("Quitter", this);
    m_quitButton->setFixedSize(80, 30);

    m_addComments = new QCheckBox("Ajouter des commentaires", this);

    m_classDefinitionLabel = new QLabel("Définition de la classe");
    m_classDefinitionLabel->setFixedSize(150, 10);

    m_optionsLabel = new QLabel("Options");
    m_optionsLabel->setFixedSize(150, 15);

    m_mainWindowLayout = new QVBoxLayout;
    m_mainWindowLayout->addWidget(m_classDefinitionLabel);

    m_classDefinitionFrame = new QFrame;
    m_classDefinitionFrame->setLineWidth(1);
    m_classDefinitionFrame->setFrameShape(QFrame::Box);
    m_classDefinitionFrame->setFrameShadow(QFrame::Sunken);
    m_classDefinitionFrame->setWindowTitle("Définition de la classe");
    m_classDefinitionFrame->setFixedSize(380, 70);

    m_classDefinitionLayout = new QFormLayout(m_classDefinitionFrame);
    m_className = new QLineEdit;
    m_parentClassName = new QLineEdit;
    m_classDefinitionLayout->addRow("&Nom :", m_className);
    m_classDefinitionLayout->addRow("Classe &mère :", m_parentClassName);

    m_optionsFrame = new QFrame;
    m_optionsFrame->setLineWidth(1);
    m_optionsFrame->setFrameShape(QFrame::Box);
    m_optionsFrame->setFrameShadow(QFrame::Sunken);
    m_optionsFrame->setWindowTitle("Options");
    m_optionsFrame->setFixedSize(380, 100);

    m_optionsLayout = new QVBoxLayout(m_optionsFrame);
    m_protectHeader = new QCheckBox("Protéger le &header contre les inclusions multiples");
    m_generateDefaultConstructor = new QCheckBox("Générer un &constructeur par défaut");
    m_generateDestructor = new QCheckBox("Générer un &destructeur");
    m_optionsLayout->addWidget(m_protectHeader);
    m_optionsLayout->addWidget(m_generateDefaultConstructor);
    m_optionsLayout->addWidget(m_generateDestructor);

    m_commentairesFrame = new QFrame;
    m_commentairesFrame->setLineWidth(1);
    m_commentairesFrame->setFrameShape(QFrame::Box);
    m_commentairesFrame->setFrameShadow(QFrame::Sunken);
    m_commentairesFrame->setFixedSize(380, 220);

    m_commentairesLayout = new QFormLayout(m_commentairesFrame);
    m_author = new QLineEdit;
    m_creationDate = new QDateEdit;
    m_classRole = new QTextEdit;
    m_author->setDisabled(true);
    m_creationDate->setDisabled(true);
    m_classRole->setDisabled(true);
    m_commentairesLayout->addRow("&Auteur :", m_author);
    m_commentairesLayout->addRow("Da&te de création :", m_creationDate);
    m_commentairesLayout->addRow("&Rôle de la classe :", m_classRole);

    m_buttons = new QHBoxLayout;
    m_buttons->addWidget(m_genererButton);
    m_buttons->addWidget(m_quitButton);
    m_buttons->setAlignment(Qt::AlignRight);

    m_mainWindowLayout->addWidget(m_classDefinitionFrame);
    m_mainWindowLayout->addWidget(m_optionsLabel);
    m_mainWindowLayout->addWidget(m_optionsFrame);
    m_mainWindowLayout->addWidget(m_addComments);
    m_mainWindowLayout->addWidget(m_commentairesFrame);
    m_mainWindowLayout->addLayout(m_buttons);

    setLayout(m_mainWindowLayout);
    setMaximumWidth(420);
    setMaximumHeight(600);

    connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_addComments, SIGNAL(stateChanged(int)), this, SLOT(changeCommentsState()));
    connect(m_genererButton, SIGNAL(clicked()), this, SLOT(generate()));
}

/**
 * FR : Fonction représentant le destructeur
 * EN : Function representing the destructor
*/
MainWindow::~MainWindow() {
}

void MainWindow::changeCommentsState() {
    if(m_author->isEnabled() && m_creationDate->isEnabled() && m_classRole->isEnabled()) {
        m_author->setDisabled(true);
        m_creationDate->setDisabled(true);
        m_classRole->setDisabled(true);
    } else {
        m_author->setDisabled(false);
        m_creationDate->setDisabled(false);
        m_classRole->setDisabled(false);
    }
}

/**
 * FR : Fonction qui permet de générer la fenêtre avec le code de la classe
 * EN : Function for generating the window with the class code
*/
void MainWindow::generate() {
    GeneratedWindow generatedWindow(this);
    QTextEdit& generatedCode = generatedWindow.getWindowCode();

    if(m_className->text().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au minimum le nom de la classe");
        return;
    } else {
        if(m_addComments->isChecked()) {
            generatedCode.append("/*");
            generatedCode.append("Auteur : " + m_author->text());
            generatedCode.append("Date de création : " + m_creationDate->text() + "\n");
            if(!(m_classRole->toPlainText() == "")) {
                generatedCode.append("Rôle : \n" + m_classRole->toPlainText());
            }
            generatedCode.append("*/\n\n");
        }
        if(m_protectHeader->isChecked()) {
            generatedCode.append("#ifndef HEADER_" + m_className->text().toUpper());
            generatedCode.append("#define HEADER_" + m_className->text().toUpper() + "\n\n");
        }
        if(m_parentClassName->text().isEmpty()) {
            generatedCode.append("class " + m_className->text() + "\n{\n");
        } else {
            generatedCode.append("class " + m_className->text() + " : public " + m_parentClassName->text() + "\n{\n");
        }
        generatedCode.append("    public:");
        if(m_generateDefaultConstructor->isChecked() && m_generateDestructor->isChecked()) {
            generatedCode.append("        " + m_className->text() + "();\n        ~" + m_className->text() + "();\n");
        } else if(m_generateDefaultConstructor->isChecked()) {
            generatedCode.append("        " + m_className->text() + "();\n");
        } else if(m_generateDestructor->isChecked()) {
            generatedCode.append("        ~" + m_className->text() + "();\n");
        } else {
            generatedCode.append("");
        }
        generatedCode.append("\n    protected:\n\n\n    private:\n\n\n}");
    }

    generatedWindow.exec();
}