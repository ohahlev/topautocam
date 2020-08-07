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

class T_VIEW_EXPORT partial_nav_adminView : public TActionView
{
  Q_OBJECT
public:
  partial_nav_adminView() : TActionView() { }
  QString toString();
};

QString partial_nav_adminView::toString()
{
  responsebody.reserve(4427);
  responsebody += QStringLiteral("<nav class=\"navbar navbar-expand-md  navbar-static ms-navbar ms-navbar-primary navbar-mode\">\n  <div class=\"container container-full\">\n    <div class=\"navbar-header\">\n      ");
  responsebody += QVariant(renderPartial("brand_admin")).toString();
  responsebody += QStringLiteral("\n    </div>\n    <div class=\"collapse navbar-collapse\" id=\"ms-navbar\">\n      <ul class=\"navbar-nav\">\n        <li class=\"nav-item\">\n          <a href=\"/admin\" class=\"nav-link animated fadeIn animation-delay-7\" \n            role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"home\">Dashboard \n          </a>\n        </li>\n        <li class=\"nav-item dropdown\">\n          <a href=\"#\" class=\"nav-link dropdown-toggle animated fadeIn animation-delay-7\" data-toggle=\"dropdown\"\n            data-hover=\"dropdown\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"vehicle\">Vehicle <i\n              class=\"zmdi zmdi-chevron-down\"></i></a>\n          <ul class=\"dropdown-menu\">\n            <li><a class=\"dropdown-item\" href=\"/admin/make\"><i class=\"zmdi zmdi-collection-bookmark\"></i> Make</a></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/model\"><i class=\"zmdi zmdi-collection-case-play\"></i> Model</a></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/body\"><i class=\"zmdi zmdi-collection-folder-image\"></i> Body</a></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/drive\"><i class=\"zmdi zmdi zmdi-collection-image-o\"></i> Drive</a></li>\n            <li class=\"dropdown-divider\"></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/grade\"><i class=\"zmdi zmdi-collection-image\"></i> Grade</a></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/color\"><i class=\"zmdi zmdi-collection-music\"></i> Color</a></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/fuel\"><i class=\"zmdi zmdi zmdi-collection-pdf\"></i> Fuel</a></li>\n            <li class=\"dropdown-divider\"></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/vehicle\"><i class=\"zmdi zmdi-collection-video\"></i> Vehicle</a></li>\n          </ul>\n        </li>\n        <!--\n        <li class=\"nav-item\">\n          <a href=\"/admin/part\" class=\"nav-link animated fadeIn animation-delay-7\"\n            role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"part\">Part \n          </a>\n        </li>\n        \n        <li class=\"nav-item dropdown\">\n          <a href=\"#\" class=\"nav-link dropdown-toggle animated fadeIn animation-delay-7\" data-toggle=\"dropdown\"\n            data-hover=\"dropdown\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"report\"> Report<i\n              class=\"zmdi zmdi-chevron-down\"></i></a>\n          <ul class=\"dropdown-menu\">\n            <li><a class=\"dropdown-item\" href=\"/admin/report/expense\"><i class=\"zmdi zmdi-view-compact\"></i> Expense</a></li>\n            \n          </ul>\n        </li>\n        -->\n        <li class=\"nav-item dropdown\">\n          <a href=\"#\" class=\"nav-link dropdown-toggle animated fadeIn animation-delay-7\" data-toggle=\"dropdown\"\n            data-hover=\"dropdown\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"news\"> News\n            <i class=\"zmdi zmdi-chevron-down\"></i>\n          </a>\n          <ul class=\"dropdown-menu\">\n            <li><a class=\"dropdown-item\" href=\"/admin/headline\"><i class=\"zmdi zmdi-view-compact\"></i> Headline</a></li>\n            <li><a class=\"dropdown-item\" href=\"/admin/gallery\"><i class=\"zmdi zmdi-view-compact\"></i> Gallery</a></li>\n          </ul>\n        </li>\n        ");
  tfetch(QString, currentUser);
  responsebody += QStringLiteral("        ");
  if(currentUser != NULL) {
  responsebody += QStringLiteral("          <li class=\"nav-item\">\n            <a href=\"/admin/user/logout\" class=\"nav-link animated fadeIn animation-delay-7\"\n              role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"user\"> Logout\n            </a>\n          </li>\n          ");
  };
  responsebody += QStringLiteral("        </ul>\n      </div>\n      <a href=\"javascript:void(0)\" class=\"ms-toggle-left btn-navbar-menu\"><i class=\"zmdi zmdi-menu\"></i></a>\n    </div>\n  </nav>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_nav_adminView)

#include "partial_nav_adminView.moc"
