#include <QtCore>
#include <TreeFrogView>
#include "vehiclemodel.h"
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

class T_VIEW_EXPORT vehiclemodel_indexView : public TActionView
{
  Q_OBJECT
public:
  vehiclemodel_indexView() : TActionView() { }
  QString toString();
};

QString vehiclemodel_indexView::toString()
{
  responsebody.reserve(5124);
    tfetch(QList<VehicleModel>, vehicleModelList);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <a href=\"/admin/model/create\" class=\"btn-circle btn-circle-raised btn-circle-danger float-right\">\n              <i class=\"fa fa-plus\" style=\"margin-left: 10px\"></i>\n            </a>\n            <i class=\"fa fa-globe\"></i> Model Management\n          </h3>\n        </div>\n        <div class=\"panel-body\">\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <div class=\"row\" id=\"Container\">\n            ");
  for (const auto &i : vehicleModelList) {
  responsebody += QStringLiteral("              <div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n                <div class=\"card\">\n                  <figure class=\"ms-thumbnail\">\n                    <img src=\"");
  responsebody += THttpUtility::htmlEscape(i.logo());
  responsebody += QStringLiteral("\" alt=\"\" class=\"img-fluid fixed-height\">\n                    <figcaption class=\"ms-thumbnail-caption text-center\">\n                      <div class=\"ms-thumbnail-caption-content\">\n                        <h4 class=\"ms-thumbnail-caption-title mb-2\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</h4>\n                        <a href=\"/admin/model/save/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\">\n                          <i class=\"zmdi zmdi-edit\"></i>\n                        </a>\n                        <a href=href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removeModelModal");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                          <i class=\"zmdi zmdi-delete\"></i>\n                        </a>\n                      </div>\n                    </figcaption>\n                  </figure>\n                  <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n                    <h3 class=\"color-primary no-mt\">actions</h3>\n                    <p>here it is</p>\n                  </div>\n                </div>\n              </div>\n              <!-- remove model modal -->\n              <div class=\"modal modal-danger\" id=\"removeModelModal");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"removeModelModalLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                <div class=\"modal-dialog modal-lg animated zoomIn animated-3x\" role=\"document\">\n                  <div class=\"modal-content\">\n                    <div class=\"modal-header\">\n                      <h3 class=\"modal-title color-secondary\" id=\"removeModelModalLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">Remove Model</h3>\n                    </div>\n                    <div class=\"modal-body\">\n                      <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/model/remove/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                        <fieldset class=\"container\">\n                          <div class=\"form-group row\">\n                            <div class=\"col-lg-10\">\n                              <h3>Are you sure to remove this model?</h3>\n                              <div class=\"card\">\n                                <div class=\"card-body mx-auto\">\n                                  <img src=\"");
  responsebody += THttpUtility::htmlEscape(i.logo());
  responsebody += QStringLiteral("\" width=\"200px\">\n                                </div>\n                              </div>\n                            </div>\n                          </div>\n                          <div class=\"form-group row\">\n                            <div class=\"col-lg-10\">\n                              <button type=\"submit\" class=\"btn btn-raised btn-danger\">Yes</button>\n                              <button type=\"button\" class=\"btn btn-primary\" data-dismiss=\"modal\">No</button>\n                            </div>\n                          </div>\n                        </fieldset>\n                      </form>\n                    </div>\n                  </div>\n                </div>\n              </div>\n              ");
  };
  responsebody += QStringLiteral("            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(vehiclemodel_indexView)

#include "vehiclemodel_indexView.moc"
