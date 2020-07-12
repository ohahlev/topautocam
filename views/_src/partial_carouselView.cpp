#include <QtCore>
#include <TreeFrogView>
#include "news.h"
#include "newsgallery.h"
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_carouselView : public TActionView
{
  Q_OBJECT
public:
  partial_carouselView() : TActionView() { }
  QString toString();
};

QString partial_carouselView::toString()
{
  responsebody.reserve(7792);
      responsebody += QStringLiteral("<div class=\"ms-hero-page ms-hero-img-coffee ms-hero-bg-success ms-hero mb-6 ms-hero-material\">\n  <span class=\"ms-hero-bg\"></span>\n  <div class=\"container\">\n    <div class=\"row\">\n      <div class=\"col-xl-6 col-lg-7\">\n        <div id=\"carousel-hero\" class=\"carousel slide carousel-fade\" data-ride=\"carousel\" data-interval=\"8000\">\n          <div class=\"carousel-inner\" role=\"listbox\">\n            ");
  tfetch(QString, foo);
  responsebody += QStringLiteral("            ");
  responsebody += QVariant(foo).toString();
  responsebody += QStringLiteral("\n            ");
  tfetch(QList<News>, newsList);
  responsebody += QStringLiteral("            ");
  for (const auto &i : newsList) {
  responsebody += QStringLiteral("              <div class=\"carousel-item news-item\">\n                <div class=\"carousel-caption\">\n                  <div class=\"ms-hero-material-text-container\">\n                    <header class=\"ms-hero-material-title animated slideInLeft animation-delay-5\">\n                      <h1 class=\"animated fadeInLeft animation-delay-15 font-smoothing\">\n                        ");
  responsebody += QVariant(i.title()).toString();
  responsebody += QStringLiteral("\n                      </h1>\n                      <h2 class=\"animated fadeInLeft animation-delay-18\">\n                        ");
  responsebody += QVariant(i.subline()).toString();
  responsebody += QStringLiteral("\n                      </h2>\n                    </header>\n                    <ul class=\"ms-hero-material-list\">\n                      <li class=\"\">\n                        <div class=\"ms-list-icon animated zoomInUp animation-delay-18\">\n                          <span class=\"ms-icon ms-icon-circle ms-icon-xlg color-warning shadow-3dp\">\n                            <i class=\"zmdi zmdi-airplane\"></i>\n                          </span>\n                        </div>\n                        <div class=\"ms-list-text animated fadeInRight animation-delay-19\">\n                          ");
  responsebody += QVariant(i.line1()).toString();
  responsebody += QStringLiteral("\n                        </div>\n                      </li>\n                      <li class=\"\">\n                        <div class=\"ms-list-icon animated zoomInUp animation-delay-20\">\n                          <span class=\"ms-icon ms-icon-circle ms-icon-xlg color-success shadow-3dp\">\n                            <i class=\"zmdi zmdi-bike\"></i>\n                          </span>\n                        </div>\n                        <div class=\"ms-list-text animated fadeInRight animation-delay-21\">\n                          ");
  responsebody += QVariant(i.line2()).toString();
  responsebody += QStringLiteral("\n                        </div>\n                      </li>\n                      <li class=\"\">\n                        <div class=\"ms-list-icon animated zoomInUp animation-delay-22\">\n                          <span class=\"ms-icon ms-icon-circle ms-icon-xlg color-danger shadow-3dp\">\n                            <i class=\"zmdi zmdi-album\"></i>\n                          </span>\n                        </div>\n                        <div class=\"ms-list-text animated fadeInRight animation-delay-23\">\n                          ");
  responsebody += QVariant(i.line3()).toString();
  responsebody += QStringLiteral("\n                        </div>\n                      </li>\n                    </ul>\n                    <div class=\"ms-hero-material-buttons text-right\" style=\"height:70px\">\n                      <div class=\"ms-hero-material-buttons text-right\">\n                        <!--\n                      <a href=\"javascript:void(0);\"\n                                                class=\"btn btn-warning btn-raised animated fadeInLeft animation-delay-24 mr-2\"><i\n                                                    class=\"zmdi zmdi-settings\"></i> Personalize</a>\n                      <a href=\"javascript:void(0);\"\n                                                class=\"btn btn-success btn-raised animated fadeInRight animation-delay-24\"><i\n                                                    class=\"zmdi zmdi-download\"></i> Download</a>\n                    -->\n                      </div>\n                    </div>\n                  </div>\n                </div>\n              </div>\n              ");
  };
  responsebody += QStringLiteral("              <div class=\"carousel-controls\">\n                <!-- Controls -->\n                <a class=\"left carousel-control animated zoomIn animation-delay-30\" href=\"#carousel-hero\"\n                                role=\"button\" data-slide=\"prev\">\n                  <i class=\"zmdi zmdi-chevron-left\"></i>\n                  <span class=\"sr-only\">Previous</span>\n                </a>\n                <a class=\"right carousel-control animated zoomIn animation-delay-30\" href=\"#carousel-hero\"\n                                role=\"button\" data-slide=\"next\">\n                  <i class=\"zmdi zmdi-chevron-right\"></i>\n                  <span class=\"sr-only\">Next</span>\n                </a>\n                <!--\n                <ol class=\"carousel-indicators\">\n                  <li data-target=\"#carousel-hero\" data-slide-to=\"0\"\n                                    class=\"animated fadeInUpBig animation-delay-27 active\"></li>\n                  <li data-target=\"#carousel-hero\" data-slide-to=\"1\"\n                                    class=\"animated fadeInUpBig animation-delay-28\"></li>\n                  <li data-target=\"#carousel-hero\" data-slide-to=\"2\"\n                                    class=\"animated fadeInUpBig animation-delay-29\"></li>\n                </ol>\n                -->\n              </div>\n            </div>\n          </div>\n        </div>\n        <div class=\"col-xl-6 col-lg-5\">\n          <div class=\"ms-hero-img animated zoomInUp animation-delay-30\">\n            <img src=\"/img/demo/mock-imac-material2.png\" alt=\"\" class=\"img-fluid\">\n            <div id=\"carousel-hero-img\" class=\"carousel carousel-fade slide\" \n            data-ride=\"carousel\" data-interval=\"3000\">\n              <!--\n              <ol class=\"carousel-indicators carousel-indicators-hero-img\">\n                <li data-target=\"#carousel-hero-img\" data-slide-to=\"0\" class=\"active\"></li>\n                <li data-target=\"#carousel-hero-img\" data-slide-to=\"1\"></li>\n                <li data-target=\"#carousel-hero-img\" data-slide-to=\"2\"></li>\n              </ol>\n              -->\n              <div class=\"carousel-inner\" role=\"listbox\">\n                <!--\n              <div class=\"ms-hero-img-slider carousel-item active\">\n                <img src=\"/img/demo/hero1.png\" alt=\"\" class=\"img-fluid\">\n              </div>\n              <div class=\"ms-hero-img-slider carousel-item\">\n                <img src=\"/img/demo/hero3.png\" alt=\"\" class=\"img-fluid\">\n              </div>\n              -->\n                ");
  tfetch(QList<NewsGallery>, newsGallery);
  responsebody += QStringLiteral("                ");
  for (const auto &i : newsGallery) {
  responsebody += QStringLiteral("                  <div class=\"ms-hero-img-slider carousel-item news-gallery\">\n                    <img src=\"");
  responsebody += QVariant(i.image()).toString();
  responsebody += QStringLiteral("\" alt=\"\" class=\"img-fluid\">\n                  </div>\n                  ");
  };
  responsebody += QStringLiteral("                </div>\n              </div>\n            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_carouselView)

#include "partial_carouselView.moc"
