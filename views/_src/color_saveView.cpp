#include <QtCore>
#include <TreeFrogView>
#include "color.h" 
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "colorvalidator.h"
#include "drivetypevalidator.h"
#include "gradevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"

class T_VIEW_EXPORT color_saveView : public TActionView
{
  Q_OBJECT
public:
  color_saveView() : TActionView() { }
  QString toString();
};

QString color_saveView::toString()
{
  responsebody.reserve(2680);
    tfetch(QVariantMap, color);
  tfetch(QString, err_name);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <i class=\"fa fa-globe\"></i> Edit Color\n          </h3>\n        </div>\n        <div class=\"panel-body\">\n          ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/color/save/");
  responsebody += THttpUtility::htmlEscape(color["id"]);
  responsebody += QStringLiteral("\">\n            <fieldset class=\"container\">\n              <input type=\"text\" name=\"color[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(color["id"]);
  responsebody += QStringLiteral("\" style=\"display: none\"/>\n          <div class=\"form-group row is-empty\">\n            <label for=\"inputName\" autocomplete=\"false\" \n        class=\"col-lg-2 control-label\">Name</label>\n            <div class=\"col-lg-10\">\n              ");
  if(err_name == NULL) {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-valid\" id=\"inputName\" placeholder=\"name\" name=\"color[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(color["name"]);
  responsebody += QStringLiteral("\" />\n                ");
  } else {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-invalid\" id=\"inputName\" placeholder=\"name\" name=\"color[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(color["name"]);
  responsebody += QStringLiteral("\" />\n                <div class=\"invalid-feedback\">\n                  ");
  responsebody += THttpUtility::htmlEscape(err_name);
  responsebody += QStringLiteral("\n                </div>\n                ");
  };
  responsebody += QStringLiteral("              </div>\n            </div>\n            <div class=\"form-group row justify-content-end\">\n              <div class=\"col-lg-10\">\n                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Save</button>\n                <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n              </div>\n            </div>\n          </fieldset>\n        </form>\n      </div>\n    </div>\n  </div>\n</div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(color_saveView)

#include "color_saveView.moc"
