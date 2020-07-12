#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_heroView : public TActionView
{
  Q_OBJECT
public:
  partial_heroView() : TActionView() { }
  QString toString();
};

QString partial_heroView::toString()
{
  responsebody.reserve(1454);
  responsebody += tr("<div class=\"ms-hero-page bg-info\">\n  <div class=\"container\">\n    <div class=\"row\">\n      <div class=\"col-lg-6 order-lg-2 text-center\">\n        <img src=\"\" alt=\"\" class=\"img-fluid animated bounceInRight animation-delay-14\">\n      </div>\n      <div class=\"col-lg-6 order-lg-1\">\n        <h1 class=\"animated fadeInDown animation-delay-4\">\n        \n        </h1>\n        <p class=\"lead lead-lg animated fadeInDown animation-delay-5\"></p>\n        <p class=\"animated fadeInDown animation-delay-6\">\n          \n        </p>\n        <!--\n        <ul class=\"list-unstyled\">\n          <li class=\"animated fadeInLeft animation-delay-7\">5.5 inches QHD AMOLED at 534ppi.</li>\n          <li class=\"animated fadeInLeft animation-delay-8\">4GB LPDDR4 RAM.</li>\n          <li class=\"animated fadeInLeft animation-delay-9\">32 or 128GB.</li>\n          <li class=\"animated fadeInLeft animation-delay-10\">Qualcomm® Snapdragon™ 821.</li>\n          <li class=\"animated fadeInLeft animation-delay-11\">12.3MP Large 1.55μm pixels.</li>\n        </ul>\n        -->\n        <a href=\"javascript:void(0)\" class=\"btn btn-raised btn-royal animated fadeInLeft animation-delay-14\">More info</a>\n        <!--\n        <a href=\"javascript:void(0)\" class=\"btn btn-raised btn-white color-info animated fadeInRight animation-delay-14\">Purchase</a>\n        -->\n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_heroView)

#include "partial_heroView.moc"
