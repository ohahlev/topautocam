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

class T_VIEW_EXPORT layouts_applicationView : public TActionView
{
  Q_OBJECT
public:
  layouts_applicationView() : TActionView() { }
  QString toString();
};

QString layouts_applicationView::toString()
{
  responsebody.reserve(2822);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"utf-8\">\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, minimum-scale=1.0, maximum-scale=1.0, user-scalable=no\">\n    <meta name=\"theme-color\" content=\"#333\">\n    <title>TOP AUTO</title>\n    <meta name=\"description\" content=\"TOP AUTO\">\n    <link rel=\"shortcut icon\" href=\"/img/favicon.png?v=3\">\n    <link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/icon?family=Material+Icons\">\n    <link rel=\"stylesheet\" href=\"/css/preload.min.css\">\n    <link rel=\"stylesheet\" href=\"/css/plugins.min.css\">\n    <link rel=\"stylesheet\" href=\"/css/style.light-blue-500.min.css\">\n    <link\n        rel=\"stylesheet\" href=\"/css/bootstrap-datepicker.min.css\">\n      <!-- my style -->\n      <link\n        rel=\"stylesheet\" href=\"/css/site.css\">\n        <!--[if lt IE 9]>\n          <script src=\"/assets/js/html5shiv.min.js\"></script>\n          <script src=\"/assets/js/respond.min.js\"></script>\n        <![endif]-->\n      </head>\n      <body>\n        <div id=\"ms-preload\" class=\"ms-preload\">\n          <div id=\"status\">\n            <div class=\"spinner\">\n              <div class=\"dot1\"></div>\n              <div class=\"dot2\"></div>\n            </div>\n          </div>\n        </div>\n        <div class=\"ms-site-container\">\n          ");
  responsebody += QVariant(renderPartial("login_modal")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("header")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("nav")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("carousel")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(yield()).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("footer")).toString();
  responsebody += QStringLiteral("\n        </div>\n        ");
  responsebody += QVariant(renderPartial("sidebar")).toString();
  responsebody += QStringLiteral("\n        <script src=\"/js/plugins.min.js\"></script>\n        <script src=\"/js/app.min.js\"></script>\n        <script src=\"/js/ecommerce.js\"></script>\n        <script src=\"/js/bootstrap-datepicker.min.js\"></script>\n        <script src=\"/js/site.js\"></script>\n        <script src=\"https://cdn.tiny.cloud/1/5p05qo54lyn29kp9xl07k0wj4wmus2v19rqu1yzgr8tws71c/tinymce/5/tinymce.min.js\" referrerpolicy=\"origin\"></script>\n      </body>\n    </html>\n");

  return responsebody;
}

T_DEFINE_VIEW(layouts_applicationView)

#include "layouts_applicationView.moc"
