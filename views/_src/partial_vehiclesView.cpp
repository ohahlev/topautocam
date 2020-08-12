#include <QtCore>
#include <TreeFrogView>
#include "vehicle.h" 
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

class T_VIEW_EXPORT partial_vehiclesView : public TActionView
{
  Q_OBJECT
public:
  partial_vehiclesView() : TActionView() { }
  QString toString();
};

QString partial_vehiclesView::toString()
{
  responsebody.reserve(2595);
    tfetch(QList<Vehicle>, vehicleList);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-md-12\">\n      ");
  responsebody += QVariant(renderPartial("vehicle_filter")).toString();
  responsebody += QStringLiteral("\n    </div>\n  </div>\n  <div class=\"row\">\n    <div class=\"col-md-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <i class=\"fa fa-globe\"></i>\n            Vehicles\n          </h3>\n        </div>\n        <div class=\"panel-body\">\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <div class=\"row color-dark\">\n            ");
  for (const auto &i : vehicleList) {
  responsebody += QStringLiteral("              <div class=\"col-md-4 col-md-6 mix laptop apple\" data-price=\"1999.99\" data-date=\"20160901\">\n                <div class=\"card wow zoomInUp\" style=\"visibility: visible; animation-name: zoomInUp;\">\n                  <div class=\"card-body overflow-hidden text-center\">\n                    <a href=\"/admin/vehicle/save/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                      <img src=\"/media/model/alphard.jpg\" alt=\"\" class=\"img-fluid center-block\"></a>\n                    <h4 class=\"text-normal text-center\">");
  responsebody += THttpUtility::htmlEscape(i.getModel().name());
  responsebody += QStringLiteral("</h4>\n                    <p>");
  responsebody += THttpUtility::htmlEscape(i.title());
  responsebody += QStringLiteral("</p>\n                    <div class=\"mt-2\">\n                      <span class=\"mr-2\">\n                        <i class=\"zmdi zmdi-star color-warning\"></i>\n                        <i class=\"zmdi zmdi-star color-warning\"></i>\n                        <i class=\"zmdi zmdi-star color-warning\"></i>\n                        <i class=\"zmdi zmdi-star color-warning\"></i>\n                        <i class=\"zmdi zmdi-star\"></i>\n                      </span>\n                      <span class=\"ms-tag ms-tag-success\">$\n                        ");
  responsebody += THttpUtility::htmlEscape(i.price());
  responsebody += QStringLiteral("</span>\n                    </div>\n                  </div>\n                </div>\n              </div>\n              ");
  };
  responsebody += QStringLiteral("            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_vehiclesView)

#include "partial_vehiclesView.moc"
