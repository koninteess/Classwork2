#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

class TextEditor : public QMainWindow {
    Q_OBJECT

public:
    TextEditor(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Simple Text Editor");
        setMinimumSize(600, 400);

        textEdit = new QTextEdit(this);
        setCentralWidget(textEdit);

        createActions();
        createMenus();
    }

private slots:
    void newFile() {
        textEdit->clear();
        setCurrentFile("");
    }

    void openFile() {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::warning(this, tr("Error"), tr("Cannot open file: %1").arg(file.errorString()));
                return;
            }
            QTextStream in(&file);
            textEdit->setText(in.readAll());
            setCurrentFile(fileName);
            file.close();
        }
    }

    void saveFile() {
        if (currentFile.isEmpty()) {
            saveFileAs();
        }
        else {
            QFile file(currentFile);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::warning(this, tr("Error"), tr("Cannot write file: %1").arg(file.errorString()));
                return;
            }
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        }
    }

    void saveFileAs() {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File As"), QDir::currentPath());
        if (!fileName.isEmpty()) {
            setCurrentFile(fileName);
            saveFile();
        }
    }

    void quit() {
        qApp->quit();
    }

private:
    void createActions() {
        newAction = new QAction(tr("&New"), this);
        newAction->setShortcut(QKeySequence::New);
        connect(newAction, &QAction::triggered, this, &TextEditor::newFile);

        openAction = new QAction(tr("&Open..."), this);
        openAction->setShortcut(QKeySequence::Open);
        connect(openAction, &QAction::triggered, this, &TextEditor::openFile);

        saveAction = new QAction(tr("&Save"), this);
        saveAction->setShortcut(QKeySequence::Save);
        connect(saveAction, &QAction::triggered, this, &TextEditor::saveFile);

        saveAsAction = new QAction(tr("Save &As..."), this);
        connect(saveAsAction, &QAction::triggered, this, &TextEditor::saveFileAs);

        quitAction = new QAction(tr("&Quit"), this);
        quitAction->setShortcut(QKeySequence::Quit);
        connect(quitAction, &QAction::triggered, this, &TextEditor::quit);
    }

    void createMenus() {
        fileMenu = menuBar()->addMenu(tr("&File"));
        fileMenu->addAction(newAction);
        fileMenu->addAction(openAction);
        fileMenu->addAction(saveAction);
        fileMenu->addAction(saveAsAction);
        fileMenu->addSeparator();
        fileMenu->addAction(quitAction);
    }

    void setCurrentFile(const QString& fileName) {
        currentFile = fileName;
        setWindowTitle(tr("%1[*] - %2").arg(currentFile.isNull() ? "Untitled" : QFileInfo(currentFile).fileName()).arg("Simple Text Editor"));
    }

    QTextEdit* textEdit;
    QString currentFile;

    QMenu* fileMenu;
    QAction* newAction;
    QAction* openAction;
    QAction* saveAction;
    QAction* saveAsAction;
    QAction* quitAction;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    TextEditor textEditor;
    textEditor.show();

    return app.exec();
}

#include "main.moc"