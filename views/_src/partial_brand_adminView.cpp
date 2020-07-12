#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_brand_adminView : public TActionView
{
  Q_OBJECT
public:
  partial_brand_adminView() : TActionView() { }
  QString toString();
};

QString partial_brand_adminView::toString()
{
  responsebody.reserve(327);
  responsebody += QStringLiteral("<a class=\"navbar-brand\" href=\"/dashboard\">\n  <!-- <img src=\"/assets/img/demo/logo-navbar.png\" alt=\"\"> -->\n  <span class=\"ms-logo ms-logo-sm\">T</span>\n  <span class=\"ms-title\">TOP <strong>AUTO</strong></span>\n  <span class=\"badge-pill badge-pill-pink\">admin</span>\n</a>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_brand_adminView)

#include "partial_brand_adminView.moc"
