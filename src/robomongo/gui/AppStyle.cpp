#include "robomongo/gui/AppStyle.h"

#include "robomongo/core/AppRegistry.h"
#include "robomongo/core/settings/SettingsManager.h"
#include <QApplication>
#include <QStyleFactory>

namespace Robomongo
{
    namespace detail
    {
        void applyStyle(const QString &styleName)
        {
            if(styleName == "Native")
            {
                QApplication::setStyle(new AppStyle);
            }
            else
            {
                QApplication::setStyle(QStyleFactory::create(styleName));
            }
        }
        QStringList getSupportedStyles()
        {
            static QStringList result = QStringList() << "Native" <<QStyleFactory::keys();
            return result;
        }

        void initStyle()
        {
            AppRegistry::instance().settingsManager()->save();
            QString style = AppRegistry::instance().settingsManager()->currentStyle();
            applyStyle(style);
        }
    }

    void AppStyle::drawControl(ControlElement element,	const QStyleOption * option,	QPainter * painter,	const QWidget * widget) const
    {
        OsStyle::drawControl(element, option, painter, widget);
    }

    void AppStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
    {
        if(element==QStyle::PE_FrameFocusRect)
            return;
        OsStyle::drawPrimitive(element, option, painter, widget);
    }

    QRect AppStyle::subElementRect( SubElement element, const QStyleOption * option, const QWidget * widget /*= 0 */ ) const
    {
        return OsStyle::subElementRect(element, option, widget);
    }
}