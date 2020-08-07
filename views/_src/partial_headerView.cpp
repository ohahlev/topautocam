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

class T_VIEW_EXPORT partial_headerView : public TActionView
{
  Q_OBJECT
public:
  partial_headerView() : TActionView() { }
  QString toString();
};

QString partial_headerView::toString()
{
  responsebody.reserve(1483);
  responsebody += QStringLiteral("<header class=\"ms-header ms-header-primary\">\n  <!--ms-header-primary-->\n  <div class=\"container container-full\">\n    <div class=\"ms-title\">\n      ");
  responsebody += QVariant(renderPartial("brand")).toString();
  responsebody += QStringLiteral("\n    </div>\n    <div class=\"header-right\">\n      <div class=\"share-menu\">\n        <ul class=\"share-menu-list\">\n          <li class=\"animated fadeInRight animation-delay-2\">\n            <a href=\"https://web.facebook.com/pg/savinautokh\" target=\"_blank\" class=\"btn-circle btn-facebook\"><i class=\"zmdi zmdi-facebook\"></i></a>\n          </li>\n        </ul>\n        <a href=\"javascript:void(0)\" class=\"btn-circle btn-circle-primary animated zoomInDown animation-delay-7\"><i class=\"zmdi zmdi-share\"></i></a>\n      </div>\n      <a href=\"admin/user/login\" class=\"btn-circle btn-circle-primary\"><i class=\"zmdi zmdi-account\"></i></a>\n      <!--\n        <form class=\"search-form animated zoomInDown animation-delay-9\">\n        <input id=\"search-box\" type=\"text\" class=\"search-input\" placeholder=\"Search...\" name=\"q\" />\n        <label for=\"search-box\"><i class=\"zmdi zmdi-search\"></i></label>\n      </form>\n      \n      <a href=\"javascript:void(0)\" class=\"btn-ms-menu btn-circle btn-circle-primary ms-toggle-left animated zoomInDown animation-delay-10\"><i class=\"zmdi zmdi-menu\"></i></a>\n      -->\n    </div>\n  </div>\n</header>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_headerView)

#include "partial_headerView.moc"
