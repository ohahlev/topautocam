#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "colorvalidator.h"
#include "drivetypevalidator.h"
#include "fueltypevalidator.h"
#include "gradevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"
#include "vehiclevalidator.h"

class T_VIEW_EXPORT user_formView : public TActionView
{
  Q_OBJECT
public:
  user_formView() : TActionView() { }
  QString toString();
};

QString user_formView::toString()
{
  responsebody.reserve(677);
  responsebody += QStringLiteral("<!DOCTYPE HTML>\n<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n</head>\n<body>\n  <h1>Login Form</h1>\n  <div style=\"color: red;\">");
  techoex(message);
  responsebody += QStringLiteral("</div>\n  ");
  responsebody += QVariant(formTag(urla("login"))).toString();
  responsebody += QStringLiteral("\n    <div>\n      User Name: <input type=\"text\" name=\"username\" value=\"\" />\n    </div>\n    <div>\n      Password: <input type=\"password\" name=\"password\" value=\"\" />\n    </div>\n    <div>\n      <input type=\"submit\" value=\"Login\" />\n    </div>\n  </form>\n</body>\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(user_formView)

#include "user_formView.moc"
