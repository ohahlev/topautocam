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
  responsebody.reserve(10623);
                responsebody += QStringLiteral("\n");
  tfetch(QList<Make>, makeList);
  tfetch(QList<VehicleModel>, modelList);
  tfetch(QList<BodyType>, bodyTypeList);
  tfetch(QList<DriveType>, driveTypeList);
  tfetch(QList<Color>, colorList);
  tfetch(QList<Grade>, gradeList);
  tfetch(QList<FuelType>, fuelTypeList);
  responsebody += QStringLiteral("\n");
  tfetch(int, make);
  tfetch(int, model);
  tfetch(int, body);
  tfetch(int, color);
  tfetch(int, grade);
  tfetch(int, fuel);
  tfetch(int, drive);
  responsebody += QStringLiteral("\n<div class=\"card card-primary\">\n  <div class=\"card-header\">\n    <h3 class=\"card-title\">Filter List</h3>\n  </div>\n  <div class=\"card-body\">\n\n    <form method=\"get\" action=\"search\">\n\n      <div class=\"row\">\n\n        <div class=\"col-md-4\">\n          <fieldset>\n            <div class=\"form-group\">\n              <label for=\"inputMake\" class=\"col-md-3 control-label\">Make</label>\n              <div class=\"col-md-9\">\n                <select class=\"selectpicker form-control is-valid\" id=\"inputMake\" name=\"make\">\n                  <option value=\"0\" selected>ALL</option>\n                  ");
  for (const auto &i : makeList) {
  responsebody += QStringLiteral("                    ");
  if (i.id() == make) {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  } else {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  };
  responsebody += QStringLiteral("                  ");
  };
  responsebody += QStringLiteral("                </select>\n              </div>\n            </div>\n          </fieldset>\n        </div>\n\n        <div class=\"col-md-4\">\n          <fieldset>\n            <div class=\"form-group\">\n              <label for=\"inputModel\" class=\"col-md-3 control-label\">Model</label>\n              <div class=\"col-md-9\">\n                <select class=\"selectpicker form-control is-valid\" id=\"inputModel\" name=\"model\">\n                  <option value=\"0\" selected>ALL</option>\n                  ");
  for (const auto &i : modelList) {
  responsebody += QStringLiteral("                    ");
  if (i.id() == model) {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  } else {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  };
  responsebody += QStringLiteral("                  ");
  };
  responsebody += QStringLiteral("                </select>\n              </div>\n            </div>\n          </fieldset>\n        </div>\n\n        <div class=\"col-md-4\">\n          <fieldset>\n            <div class=\"form-group\">\n              <label for=\"inputBodyType\" class=\"col-md-3 control-label\">Body</label>\n              <div class=\"col-md-9\">\n                <select class=\"selectpicker form-control is-valid\" id=\"inputBodyType\" name=\"body\">\n                  <option value=\"0\" selected>ALL</option>\n                  ");
  for (const auto &i : bodyTypeList) {
  responsebody += QStringLiteral("                    ");
  if (i.id() == body) {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  } else {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  };
  responsebody += QStringLiteral("                  ");
  };
  responsebody += QStringLiteral("                </select>\n              </div>\n            </div>\n          </fieldset>\n        </div>\n      </div>\n\n      <div class=\"row\">\n\n        <div class=\"col-md-4\">\n          <fieldset>\n            <div class=\"form-group\">\n              <label for=\"inputColor\" autocomplete=\"false\" class=\"col-md-3 control-label\">Color</label>\n              <div class=\"col-md-9\">\n                <select class=\"selectpicker form-control is-valid\" id=\"inputColor\" name=\"color\">\n                  <option value=\"0\" selected>ALL</option>\n                  ");
  for(const auto &i : colorList) {
  responsebody += QStringLiteral("                    ");
  if (i.id() == color) {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  } else {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  };
  responsebody += QStringLiteral("                  ");
  };
  responsebody += QStringLiteral("                </select>\n              </div>\n            </div>\n          </fieldset>\n        </div>\n\n        <div class=\"col-md-4\">\n          <fieldset>\n            <div class=\"form-group\">\n              <label for=\"inputGrade\" autocomplete=\"false\" class=\"col-md-3 control-label\">Grade</label>\n              <div class=\"col-md-9\">\n                <select class=\"selectpicker form-control is-valid\" id=\"inputGrade\" name=\"grade\">\n                  <option value=\"0\" selected>ALL</option>\n                  ");
  for(const auto &i : gradeList) {
  responsebody += QStringLiteral("                    ");
  if (i.id() == grade) {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  } else {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  };
  responsebody += QStringLiteral("                  ");
  };
  responsebody += QStringLiteral("                </select>\n              </div>\n            </div>\n          </fieldset>\n        </div>\n\n        <div class=\"col-md-4\">\n          <fieldset>\n            <div class=\"form-group\">\n              <label for=\"inputGrade\" autocomplete=\"false\" class=\"col-md-3 control-label\">Fuel</label>\n              <div class=\"col-md-9\">\n                <select class=\"selectpicker form-control is-valid\" id=\"inputGrade\" name=\"fuel\">\n                  <option value=\"0\" selected>ALL</option>\n                  ");
  for(const auto &i : fuelTypeList) {
  responsebody += QStringLiteral("                    ");
  if (i.id() == fuel) {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  } else {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  };
  responsebody += QStringLiteral("                  ");
  };
  responsebody += QStringLiteral("                </select>\n              </div>\n            </div>\n          </fieldset>\n        </div>\n\n      </div>\n\n      <div class=\"row\">\n\n        <div class=\"col-md-4\">\n          <fieldset>\n            <div class=\"form-group\">\n              <label for=\"inputModel\" class=\"col-md-3 control-label\">Drive</label>\n              <div class=\"col-md-9\">\n                <select class=\"selectpicker form-control is-valid\" id=\"inputModel\" name=\"drive\">\n                  <option value=\"0\" selected>ALL</option>\n                  ");
  for (const auto &i : driveTypeList) {
  responsebody += QStringLiteral("                    ");
  if (i.id() == drive) {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  } else {
  responsebody += QStringLiteral("                      <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                    ");
  };
  responsebody += QStringLiteral("                  ");
  };
  responsebody += QStringLiteral("                </select>\n              </div>\n            </div>\n          </fieldset>\n        </div>\n      </div>\n\n      <div class=\"row\">\n        <div class=\"col-md-3\">\n          <button class=\"btn btn-danger btn-block no-mb mt-2\" id=\"Reset\" type=\"submit\">\n            filter\n          </button>\n        </div>\n      </div>\n    </form>\n\n  </div>\n</div>");

  return responsebody;
}

T_DEFINE_VIEW(partial_vehicle_filterView)

#include "partial_vehicle_filterView.moc"
