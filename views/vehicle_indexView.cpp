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

class T_VIEW_EXPORT vehicle_indexView : public TActionView
{
  Q_OBJECT
public:
  vehicle_indexView() : TActionView() { }
  QString toString();
};

QString vehicle_indexView::toString()
{
  responsebody.reserve(7634);
    tfetch(QList<Vehicle>, vehicleList);
  responsebody += QStringLiteral("<div class=\"container\">\n    <div class=\"row\">\n        <div class=\"col-lg-12\">\n            <div class=\"card card-primary\">\n                <div class=\"card-header\">\n                    <h3 class=\"card-title\">\n                        <i class=\"fa fa-filter\"></i>\n                        Filter List\n                    </h3>\n                </div>\n                <div class=\"card-body\">\n                    <form class=\"form-horizontal\" id=\"Filters\">\n                        <fieldset></fieldset>\n                    </form>\n                </div>\n            </div>\n        </div>\n    </div>\n\n    <div class=\"row\">\n        <div class=\"col-lg-12\">\n            <div class=\"panel panel-primary\">\n                <div class=\"panel-heading\">\n                    <h3 class=\"panel-title\">\n                        <a href=\"/admin/vehicle/create\" class=\"btn-circle btn-circle-raised btn-circle-danger float-right\">\n                            <i class=\"fa fa-plus\" style=\"margin-left: 10px\"></i>\n                        </a>\n                        <i class=\"fa fa-globe\"></i>\n                        Vehicles\n                    </h3>\n                </div>\n                <div class=\"panel-body\">\n                    ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n                    <div class=\"row color-dark\">\n                        ");
  for (const auto &i : vehicleList) {
  responsebody += QStringLiteral("                            <div class=\"col-lg-4 col-md-6 mix laptop apple\" data-price=\"1999.99\" data-date=\"20160901\">\n                                <div class=\"card wow zoomInUp\" style=\"visibility: visible; animation-name: zoomInUp;\">\n                                    <div class=\"card-body overflow-hidden text-center\">\n                                        <a href=\"/admin/vehicle/save/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                                            <img src=\"/media/model/alphard.jpg\" alt=\"\" class=\"img-fluid center-block\"></a>\n                                            <h4 class=\"text-normal text-center\">");
  responsebody += THttpUtility::htmlEscape(i.getModel().name());
  responsebody += QStringLiteral("</h4>\n                                            <p>");
  responsebody += THttpUtility::htmlEscape(i.title());
  responsebody += QStringLiteral("</p>\n                                            <div class=\"mt-2\">\n                                                <span class=\"mr-2\">\n                                                    <i class=\"zmdi zmdi-star color-warning\"></i>\n                                                    <i class=\"zmdi zmdi-star color-warning\"></i>\n                                                    <i class=\"zmdi zmdi-star color-warning\"></i>\n                                                    <i class=\"zmdi zmdi-star color-warning\"></i>\n                                                    <i class=\"zmdi zmdi-star\"></i>\n                                                </span>\n                                                <span class=\"ms-tag ms-tag-success\">$\n                                                    ");
  responsebody += THttpUtility::htmlEscape(i.price());
  responsebody += QStringLiteral("</span>\n                                            </div>\n                                            <a href=\"javascript:void(0)\" class=\"btn btn-danger btn-sm btn-block btn-raised mt-2 no-mb\" data-toggle=\"modal\" data-target=\"#removeVehicleModal");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                                                <i class=\"zmdi zmdi-delete\"></i>\n                                                remove\n                                            </a>\n                                        </div>\n                                    </div>\n                                </div>\n\n                                <div class=\"modal modal-danger\" id=\"removeVehicleModal");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"removeVehicleModalLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                                    <div class=\"modal-dialog modal-lg animated zoomIn animated-3x\" role=\"document\">\n                                        <div class=\"modal-content\">\n                                            <div class=\"modal-header\">\n                                                <h3 class=\"modal-title color-secondary\" id=\"removeVehicleModalLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">Remove Vehicle</h3>\n                                            </div>\n                                            <div class=\"modal-body\">\n                                                <form class=\"form-horizontal\" method=\"POST\" action=\"vehicle/remove/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                                                    <fieldset class=\"container\">\n                                                        <div class=\"form-group row\">\n                                                            <div class=\"col-lg-10\">\n                                                                <h3>Are you sure to remove this vehicle?</h3>\n                                                                <div class=\"card\">\n                                                                    <div class=\"card-body\">\n                                                                        <p>\n                                                                            ");
  responsebody += QVariant(i.title()).toString();
  responsebody += QStringLiteral("\n                                                                        </p>\n                                                                    </div>\n                                                                </div>\n                                                            </div>\n                                                        </div>\n                                                        <div class=\"form-group row\">\n                                                            <div class=\"col-lg-10\">\n                                                                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Yes</button>\n                                                                <button type=\"button\" class=\"btn btn-primary\" data-dismiss=\"modal\">No</button>\n                                                            </div>\n                                                        </div>\n                                                    </fieldset>\n                                                </form>\n                                            </div>\n                                        </div>\n                                    </div>\n                                </div>\n\n                            ");
  };
  responsebody += QStringLiteral("                        </div>\n                    </div>\n                </div>\n            </div>\n        </div>\n    </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(vehicle_indexView)

#include "vehicle_indexView.moc"
