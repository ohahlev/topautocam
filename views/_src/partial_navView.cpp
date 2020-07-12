#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_navView : public TActionView
{
  Q_OBJECT
public:
  partial_navView() : TActionView() { }
  QString toString();
};

QString partial_navView::toString()
{
  responsebody.reserve(1688);
  responsebody += QStringLiteral("<nav class=\"navbar navbar-expand-md  navbar-static ms-navbar ms-navbar-primary\">\n  <div class=\"container container-full\">\n    <div class=\"collapse navbar-collapse\" id=\"ms-navbar\">\n      <ul class=\"navbar-nav\">\n        <li class=\"nav-item\">\n          <a href=\"/\" class=\"nav-link animated fadeIn animation-delay-7\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"home\">\n            Home\n          </a>\n        </li>\n        <li class=\"nav-item\">\n          <a href=\"/vehicle\" class=\"nav-link animated fadeIn animation-delay-7\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"component\">\n            Vehicle\n          </a>\n        </li>\n        <li class=\"nav-item\">\n          <a href=\"/part\" class=\"nav-link animated fadeIn animation-delay-7\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"component\">\n            Part\n          </a>\n        </li>\n        <li class=\"nav-item\">\n          <a href=\"/service\" class=\"nav-link animated fadeIn animation-delay-7\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"component\">\n            Service\n          </a>\n        </li>\n        <li class=\"nav-item\">\n          <a href=\"/finance\" class=\"nav-link animated fadeIn animation-delay-7\" role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\" data-name=\"component\">\n            Finance\n          </a>\n        </li>\n      </ul>\n    </div>\n    <a href=\"javascript:void(0)\" class=\"ms-toggle-left btn-navbar-menu\"><i class=\"zmdi zmdi-menu\"></i></a>\n  </div>\n</nav>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_navView)

#include "partial_navView.moc"
