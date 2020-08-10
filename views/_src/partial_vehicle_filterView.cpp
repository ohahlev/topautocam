#include <QtCore>
#include <TreeFrogView>
#include "make.h" 
#include "vehiclemodel.h" 
#include "grade.h" 
#include "color.h" 
#include "drivetype.h" 
#include "fueltype.h" 
#include "bodytype.h" 
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

class T_VIEW_EXPORT partial_vehicle_filterView : public TActionView
{
  Q_OBJECT
public:
  partial_vehicle_filterView() : TActionView() { }
  QString toString();
};

QString partial_vehicle_filterView::toString()
{
  responsebody.reserve(9635);
                responsebody += QStringLiteral("\n");
  tfetch(QList<Make>, makeList);
  tfetch(QList<VehicleModel>, modelList);
  tfetch(QList<BodyType>, bodyTypeList);
  tfetch(QList<DriveType>, driveTypeList);
  tfetch(QList<Color>, colorList);
  tfetch(QList<Grade>, gradeList);
  tfetch(QList<FuelType>, fuelTypeList);
  responsebody += QStringLiteral("\n\n<div class=\"row\">\n  <div class=\"col-md-12\">\n    \n    <div class=\"card card-primary\">\n    \n      <div class=\"card-header\">\n        <h3 class=\"card-title\">Filter List</h3>\n      </div>\n\n      <div class=\"card-body\">\n      \n        <div class=\"row\">\n          \n          <div class=\"col-md-12\">\n            \n            <form method=\"get\" action=\"search\">\n              \n                <div class=\"row\">\n             \n                  <div class=\"col-md-3\">\n                    \n                    <fieldset>\n                      \n                      <div class=\"form-group\">\n                      <label for=\"inputMake\" class=\"col-md-3 control-label\">Make</label>\n                      <div class=\"col-md-9\">\n                        <select class=\"selectpicker form-control is-valid\" id=\"inputMake\" name=\"makeId\">\n                          ");
  for (const auto &i : makeList) {
  responsebody += QStringLiteral("                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                            ");
  };
  responsebody += QStringLiteral("                          </select>\n                        </div>\n                      </div>\n                    </fieldset>\n\n                  </div>\n\n                  <div class=\"col-md-3\">\n                  \n                      <fieldset>\n                  \n                      <div class=\"form-group\">\n                        <label for=\"inputModel\" class=\"col-md-3 control-label\">Model</label>\n                        <div class=\"col-md-9\">\n                          <select class=\"selectpicker form-control is-valid\" id=\"inputModel\" name=\"modelId\">\n                            ");
  for (const auto &i : modelList) {
  responsebody += QStringLiteral("                              <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                            ");
  };
  responsebody += QStringLiteral("                          </select>\n                        </div>\n                        </div>\n                      </fieldset>\n                    \n                  </div>\n\n                <div class=\"col-md-3\">\n                  \n                      <fieldset>\n                  \n                      <div class=\"form-group\">\n                        <label for=\"inputBodyType\" class=\"col-md-3 control-label\">Body</label>\n                        <div class=\"col-md-9\">\n                          <select class=\"selectpicker form-control is-valid\" id=\"inputBodyType\" name=\"bodyId\">\n                            ");
  for (const auto &i : bodyTypeList) {
  responsebody += QStringLiteral("                              <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                            ");
  };
  responsebody += QStringLiteral("                          </select>\n                        </div>\n                        </div>\n                      </fieldset>\n                    \n                  </div>\n\n                  <div class=\"col-md-3\">\n                  \n                      <fieldset>\n                  \n                      <div class=\"form-group\">\n                        <label for=\"inputModel\" class=\"col-md-3 control-label\">Drive</label>\n                        <div class=\"col-md-9\">\n                          <select class=\"selectpicker form-control is-valid\" id=\"inputModel\" name=\"driveId\">\n                            ");
  for (const auto &i : driveTypeList) {
  responsebody += QStringLiteral("                              <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                            ");
  };
  responsebody += QStringLiteral("                          </select>\n                        </div>\n                        </div>\n                      </fieldset>\n                    \n                  </div>\n                  \n                </div>\n\n                <div class=\"row\">\n\n                    <div class=\"col-md-4\">\n                    \n                      <fieldset>\n                        <div class=\"form-group\">\n                        <label for=\"inputColor\" autocomplete=\"false\" class=\"col-md-3 control-label\">Color</label>\n                        <div class=\"col-md-9\">\n                              <select class=\"selectpicker form-control is-valid\" id=\"inputColor\" name=\"colorId\">\n                                ");
  for(const auto &i : colorList) {
  responsebody += QStringLiteral("                                <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                ");
  };
  responsebody += QStringLiteral("                              </select>\n                        </div>\n                        </div>\n                      </fieldset>\n\n                    </div>\n\n                    <div class=\"col-md-4\">\n                    \n                      <fieldset>\n                        <div class=\"form-group\">\n                        <label for=\"inputGrade\" autocomplete=\"false\" class=\"col-md-3 control-label\">Grade</label>\n                        \n                        <div class=\"col-md-9\">\n                            \n                              <select class=\"selectpicker form-control is-valid\" id=\"inputGrade\" name=\"gradeId\">\n                                ");
  for(const auto &i : gradeList) {
  responsebody += QStringLiteral("                                <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                ");
  };
  responsebody += QStringLiteral("                              </select>\n\n                        </div>\n                        </div>\n                      </fieldset>\n\n                    </div>\n\n                           <div class=\"col-md-4\">\n                    \n                      <fieldset>\n\n                        <div class=\"form-group\">\n\n                        <label for=\"inputGrade\" autocomplete=\"false\" class=\"col-md-3 control-label\">Fuel</label>\n                        \n                        <div class=\"col-md-9\">\n                            \n                              <select class=\"selectpicker form-control is-valid\" id=\"inputGrade\" name=\"fuelId\">\n                                ");
  for(const auto &i : fuelTypeList) {
  responsebody += QStringLiteral("                                <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                ");
  };
  responsebody += QStringLiteral("                              </select>\n\n                        </div>\n                        </div>\n                      </fieldset>\n\n                    </div>\n                \n                    <!--\n                    <div class=\"col-md-4\">\n                      <form class=\"form-horizontal\">\n                        <h4>Sort by</h4>\n                        <select id=\"SortSelect\" class=\"form-control selectpicker\">\n                          <option value=\"random\">Popular</option>\n                          <option value=\"price:asc\">Price ASC</option>\n                          <option value=\"price:desc\">Price DESC</option>\n                          <option value=\"date:asc\">Release ASC</option>\n                          <option value=\"date:desc\">Release DESC</option>\n                        </select>\n                      </form>\n                      <button class=\"btn btn-danger btn-block no-mb mt-2\" id=\"Reset\"><i class=\"zmdi zmdi-delete\"></i> Clear Filters</button>\n                    </div>\n                    -->\n\n                </div>\n\n                <div class=\"row\">\n                    <div class=\"col-md-3\">\n                      <button class=\"btn btn-danger btn-block no-mb mt-2\" id=\"Reset\" type=\"submit\">\n                        filter\n                      </button>\n                    </div>\n                </div>\n\n              </form>\n              \n            </div>\n          </div>\n      </div>\n      </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_vehicle_filterView)

#include "partial_vehicle_filterView.moc"
