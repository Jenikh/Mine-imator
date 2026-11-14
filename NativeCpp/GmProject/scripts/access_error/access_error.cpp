// Native C++ port of:
// GmProject/scripts/access_error/access_error.gml
//
// Original GML behavior:
// Display a startup error explaining that administrative rights or
// reinstalling into another location may resolve the problem.

#include <QMessageBox>
#include <QString>

namespace MineImator
{
    void access_error(QWidget* parent)
    {
        QMessageBox::critical(
            parent,
            QStringLiteral("Mine-imator startup error"),
            QStringLiteral(
                "There was an error with the Mine-imator startup.\n"
                "Make sure you have administrative rights "
                "(Right click->Run as administrator) or try re-installing "
                "the program in a different location."
            )
        );
    }
}
