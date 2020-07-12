#include <QtCore>
#include <TreeFrogView>
#include "drivetype.h" 
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "drivetypevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"

class T_VIEW_EXPORT drivetype_saveView : public TActionView
{
  Q_OBJECT
public:
  drivetype_saveView() : TActionView() { }
  QString toString();
};

QString drivetype_saveView::toString()
{
  responsebody.reserve(2713);
    tfetch(QVariantMap, driveType);
  tfetch(QString, err_name);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <i class=\"fa fa-globe\"></i> Edit Drive\n          </h3>\n        </div>\n        <div class=\"panel-drive\">\n          ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/drive/save/");
  responsebody += THttpUtility::htmlEscape(driveType["id"]);
  responsebody += QStringLiteral("\">\n            <fieldset class=\"container\">\n              <input type=\"text\" name=\"driveType[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(driveType["id"]);
  responsebody += QStringLiteral("\" style=\"display: none\"/>\n          <div class=\"form-group row is-empty\">\n            <label for=\"inputName\" autocomplete=\"false\" \n        class=\"col-lg-2 control-label\">Name</label>\n            <div class=\"col-lg-10\">\n              ");
  if(err_name == NULL) {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-valid\" id=\"inputName\" placeholder=\"name\" name=\"driveType[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(driveType["name"]);
  responsebody += QStringLiteral("\" />\n                ");
  } else {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-invalid\" id=\"inputName\" placeholder=\"name\" name=\"driveType[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(driveType["name"]);
  responsebody += QStringLiteral("\" />\n                <div class=\"invalid-feedback\">\n                  ");
  responsebody += THttpUtility::htmlEscape(err_name);
  responsebody += QStringLiteral("\n                </div>\n                ");
  };
  responsebody += QStringLiteral("              </div>\n            </div>\n            <div class=\"form-group row justify-content-end\">\n              <div class=\"col-lg-10\">\n                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Save</button>\n                <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n              </div>\n            </div>\n          </fieldset>\n        </form>\n      </div>\n    </div>\n  </div>\n</div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(drivetype_saveView)

#include "drivetype_saveView.moc"
