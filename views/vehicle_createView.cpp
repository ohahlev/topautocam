#include <QtCore>
#include <TreeFrogView>
#include "vehicle.h" 
#include "make.h" 
#include "vehiclemodel.h" 
#include "grade.h" 
#include "color.h" 
#include "fueltype.h" 
#include "bodytype.h" 
#include "drivetype.h" 
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

class T_VIEW_EXPORT vehicle_createView : public TActionView
{
  Q_OBJECT
public:
  vehicle_createView() : TActionView() { }
  QString toString();
};

QString vehicle_createView::toString()
{
  responsebody.reserve(32000);
                  responsebody += QStringLiteral("\n");
  tfetch(QList<Make>, makeList);
  tfetch(QList<VehicleModel>, modelList);
  tfetch(QList<Grade>, gradeList);
  tfetch(QList<Color>, colorList);
  tfetch(QList<FuelType>, fuelList);
  tfetch(QList<DriveType>, driveList);
  tfetch(QList<BodyType>, bodyList);
  responsebody += QStringLiteral("\n");
  tfetch(QVariantMap, vehicle);
  tfetch(QString, err_title);
  tfetch(QString, err_detail);
  tfetch(QString, err_code);
  tfetch(QString, err_frameNo);
  tfetch(QString, err_manufacturingDate);
  tfetch(QString, err_depositDate);
  tfetch(QString, err_engine);
  tfetch(QString, err_mileage);
  tfetch(QString, err_vehicleStatus);
  tfetch(QString, err_inventoryStatus);
  tfetch(QString, err_price);
  responsebody += QStringLiteral("    <div class=\"container\"> <div class=\"row\">\n        <div class=\"col-lg-12\">\n            <div class=\"panel panel-primary\">\n                <div class=\"panel-heading\">\n                    <h3 class=\"panel-title\">\n                        <i class=\"fa fa-globe\"></i>\n                        Create Vehicle\n                    </h3>\n                </div>\n                <div class=\"panel-body\">\n                    ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n                    <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/vehicle/create\" enctype=\"multipart/form-data\">\n\n                        <div class=\"row\">\n                            <div class=\"col\">\n                                <div class=\"card\">\n                                    <div class=\"card-body\">\n                                        <div class=\"form-group is-empty px-5\">\n                                            <div class=\"row\">\n                                                <label for=\"inputManufacturingDate\" class=\"control-label\">Manufacturing Date</label>\n                                            </div>\n                                            <div class=\"row\">\n                                                ");
  if(err_manufacturingDate == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputManufacturingDate\" class=\"datepicker form-control is-valid\" name=\"vehicle[manufacturingDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["manufacturingDate"]);
  responsebody += QStringLiteral("\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputManufacturingDate\" class=\"datepicker form-control is-invalid\" name=\"vehicle[manufacturingDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["manufacturingDate"]);
  responsebody += QStringLiteral("\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_manufacturingDate);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n                                    </div>\n                                </div>\n                            </div>\n                            <div class=\"col\">\n                                <div class=\"card\">\n                                    <div class=\"card-body\">\n                                        <div class=\"form-group is-empty px-5\">\n                                            <div class=\"row\">\n                                                <label for=\"inputDepositDate\" class=\"control-label\">Deposit Date</label>\n                                            </div>\n                                            <div class=\"row\">\n                                                ");
  if(err_depositDate == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputDepositDate\" class=\"datepicker form-control is-valid\" name=\"vehicle[depositDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["depositDate"]);
  responsebody += QStringLiteral("\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputDepositDate\" class=\"datepicker form-control is-invalid\" name=\"vehicle[depositDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["depositDate"]);
  responsebody += QStringLiteral("\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_depositDate);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n                                    </div>\n                                </div>\n                            </div>\n                        </div>\n\n                        <div class=\"row\">\n                            <div class=\"col-lg-12\">\n                                <div class=\"card\">\n                                    <div class=\"card-body\">\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputMake\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Make</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputMake\" name=\"vehicle[makeId]\">\n                                                    ");
  for (const auto &i : makeList) {
  responsebody += QStringLiteral("                                                        ");
  if (vehicle["makeId"] == i.id()) {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  } else {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  };
  responsebody += QStringLiteral("                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputModel\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Model</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputModel\" name=\"vehicle[modelId]\">\n                                                    ");
  for (const auto &i : modelList) {
  responsebody += QStringLiteral("                                                        ");
  if (vehicle["modelId"] == i.id()) {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  } else {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  };
  responsebody += QStringLiteral("                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputBody\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Body</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputBody\" name=\"vehicle[bodyId]\">\n                                                    ");
  for(const auto &i : bodyList) {
  responsebody += QStringLiteral("                                                        ");
  if (vehicle["bodyId"] == i.id()) {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  } else {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  };
  responsebody += QStringLiteral("                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputDrive\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Drive</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputDrive\" name=\"vehicle[driveId]\">\n                                                    ");
  for(const auto &i : driveList) {
  responsebody += QStringLiteral("                                                        ");
  if (vehicle["driveId"] == i.id()) {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  } else {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  };
  responsebody += QStringLiteral("                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputColor\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Color</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputColor\" name=\"vehicle[colorId]\">\n                                                    ");
  for(const auto &i : colorList) {
  responsebody += QStringLiteral("                                                        ");
  if (vehicle["colorId"] == i.id()) {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  } else {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  };
  responsebody += QStringLiteral("                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputGrade\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Grade</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputGrade\" name=\"vehicle[gradeId]\">\n                                                    ");
  for(const auto &i : gradeList) {
  responsebody += QStringLiteral("                                                        ");
  if (vehicle["gradeId"] == i.id()) {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  } else {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  };
  responsebody += QStringLiteral("                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputFuel\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Fuel</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputFuel\" name=\"vehicle[fuelId]\">\n                                                    ");
  for (const auto &i : fuelList) {
  responsebody += QStringLiteral("                                                        ");
  if (vehicle["fuelId"] == i.id()) {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" selected>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  } else {
  responsebody += QStringLiteral("                                                            <option value=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</option>\n                                                        ");
  };
  responsebody += QStringLiteral("                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                    </div>\n                                </div>\n                            </div>\n                        </div>\n\n                        <div class=\"row\">\n                            <div class=\"col-lg-12\">\n                                <div class=\"card\">\n                                    <div class=\"card-body\">\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputStatus\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Status</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputStatus\" name=\"vehicle[vehicleStatus]\">\n                                                    ");
  if (vehicle["vehicleStatus"] == "OLD") {
  responsebody += QStringLiteral("                                                        <option value=\"OLD\" selected>OLD</option>\n                                                        <option value=\"NEW\">NEW</option>\n                                                    ");
  } else {
  responsebody += QStringLiteral("                                                        <option value=\"OLD\">OLD</option>\n                                                        <option value=\"NEW\" selected>NEW</option>\n                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputInventoryStatus\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Inventory Status</label>\n                                            <div class=\"col-lg-10\">\n                                                <select class=\"selectpicker form-control is-valid\" id=\"inputInventoryStatus\" name=\"vehicle[inventoryStatus]\">\n                                                    ");
  if (vehicle["inventoryStatus"] == "SOLD") {
  responsebody += QStringLiteral("                                                        <option value=\"SOLD\" selected>SOLD</option>\n                                                        <option value=\"STOCKED\">STOCKED</option>\n                                                    ");
  } else {
  responsebody += QStringLiteral("                                                        <option value=\"SOLD\">SOLD</option>\n                                                        <option value=\"STOCKED\" selected>STOCKED</option>\n                                                    ");
  };
  responsebody += QStringLiteral("                                                </select>\n                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputTitle\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Title</label>\n                                            <div class=\"col-lg-10\">\n                                                ");
  if(err_title == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" class=\"form-control is-valid\" id=\"inputTitle\" placeholder=\"title\" name=\"vehicle[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["title"]);
  responsebody += QStringLiteral("\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" class=\"form-control is-invalid\" id=\"inputTitle\" placeholder=\"title\" name=\"vehicle[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["title"]);
  responsebody += QStringLiteral("\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_title);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputFrameNo\" class=\"col-lg-2 control-label\">Frame No</label>\n                                            <div class=\"col-lg-10\">\n                                                ");
  if(err_frameNo == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputFrameNo\" class=\"form-control is-valid\" placeholder=\"frameNo\" name=\"vehicle[frameNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["frameNo"]);
  responsebody += QStringLiteral("\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputFrameNo\" class=\"form-control is-invalid\" placeholder=\"frameNo\" name=\"vehicle[frameNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["frameNo"]);
  responsebody += QStringLiteral("\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_frameNo);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputCode\" class=\"col-lg-2 control-label\">Code</label>\n                                            <div class=\"col-lg-10\">\n                                                ");
  if(err_code == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputCode\" class=\"form-control is-valid\" placeholder=\"code\" name=\"vehicle[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["code"]);
  responsebody += QStringLiteral("\" readonly=\"\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputCode\" class=\"form-control is-invalid\" placeholder=\"code\" name=\"vehicle[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["code"]);
  responsebody += QStringLiteral("\" readonly=\"\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_code);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputEngine\" class=\"col-lg-2 control-label\">Engine</label>\n                                            <div class=\"col-lg-10\">\n                                                ");
  if(err_engine == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputEngine\" class=\"form-control is-valid\" placeholder=\"engine\" name=\"vehicle[engine]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["engine"]);
  responsebody += QStringLiteral("\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputEngine\" class=\"form-control is-invalid\" placeholder=\"engine\" name=\"vehicle[engine]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["engine"]);
  responsebody += QStringLiteral("\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_engine);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputMileage\" class=\"col-lg-2 control-label\">Mileage</label>\n                                            <div class=\"col-lg-10\">\n                                                ");
  if(err_mileage == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputMileage\" class=\"form-control is-valid\" placeholder=\"mileage\" name=\"vehicle[mileage]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["mileage"]);
  responsebody += QStringLiteral("\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" id=\"inputMileage\" class=\"form-control is-invalid\" placeholder=\"mileage\" name=\"vehicle[mileage]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["mileage"]);
  responsebody += QStringLiteral("\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_mileage);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n                                        <div class=\"form-group row is-empty\">\n                                            <label for=\"inputDetail\" class=\"col-lg-2 control-label\">Detail</label>\n                                            <div class=\"col-lg-10\">\n                                                ");
  if(err_detail == NULL) {
  responsebody += QStringLiteral("                                                    <input type=\"text\" class=\"editor form-control is-valid\" placeholder=\"detail\" name=\"vehicle[detail]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["detail"]);
  responsebody += QStringLiteral("\"/>\n                                                ");
  } else {
  responsebody += QStringLiteral("                                                    <input type=\"text\" class=\"editor form-control is-invalid\" placeholder=\"detail\" name=\"vehicle[detail]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["detail"]);
  responsebody += QStringLiteral("\"/>\n                                                    <div class=\"invalid-feedback\">\n                                                        ");
  responsebody += THttpUtility::htmlEscape(err_detail);
  responsebody += QStringLiteral("\n                                                    </div>\n                                                ");
  };
  responsebody += QStringLiteral("                                            </div>\n                                        </div>\n                                    </div>\n                                </div>\n                            </div>\n                        </div>\n                        <div class=\"row\">\n                            <div class=\"col-lg-12\">\n                                <div class=\"card\">\n                                    <div class=\"card-body\">\n                                        <fieldset class=\"container\">\n                                            <div class=\"form-group row\">\n                                                <label for=\"inputFile\" class=\"col-lg-2 control-label\">Files</label>\n                                                <div class=\"col-lg-10\">\n                                                    <input type=\"text\" readonly=\"\" class=\"form-control\" placeholder=\"Browse...\"/>\n                                                    <input type=\"file\" name=\"picture[]\" id=\"inputFile\" multiple=\"\"/>\n                                                </div>\n                                            </div>\n                                        </fieldset>\n                                    </div>\n                                </div>\n                            </div>\n                        </div>\n\n                        <hr/>\n                        <div class=\"form-group row justify-content-end\">\n                            <div class=\"col-lg-10\">\n                                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Create</button>\n                                <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n                            </div>\n                        </div>\n                    </form>\n                </div>\n            </div>\n        </div>\n    </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(vehicle_createView)

#include "vehicle_createView.moc"
