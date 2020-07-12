#include <QtCore>
#include <TreeFrogView>
#include "grade.h" 
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "drivetypevalidator.h"
#include "gradevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"

class T_VIEW_EXPORT grade_saveView : public TActionView
{
  Q_OBJECT
public:
  grade_saveView() : TActionView() { }
  QString toString();
};

QString grade_saveView::toString()
{
  responsebody.reserve(2681);
    tfetch(QVariantMap, grade);
  tfetch(QString, err_name);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <i class=\"fa fa-globe\"></i> Edit Grade\n          </h3>\n        </div>\n        <div class=\"panel-grade\">\n          ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/grade/save/");
  responsebody += THttpUtility::htmlEscape(grade["id"]);
  responsebody += QStringLiteral("\">\n            <fieldset class=\"container\">\n              <input type=\"text\" name=\"grade[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(grade["id"]);
  responsebody += QStringLiteral("\" style=\"display: none\"/>\n          <div class=\"form-group row is-empty\">\n            <label for=\"inputName\" autocomplete=\"false\" \n        class=\"col-lg-2 control-label\">Name</label>\n            <div class=\"col-lg-10\">\n              ");
  if(err_name == NULL) {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-valid\" id=\"inputName\" placeholder=\"name\" name=\"grade[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(grade["name"]);
  responsebody += QStringLiteral("\" />\n                ");
  } else {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-invalid\" id=\"inputName\" placeholder=\"name\" name=\"grade[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(grade["name"]);
  responsebody += QStringLiteral("\" />\n                <div class=\"invalid-feedback\">\n                  ");
  responsebody += THttpUtility::htmlEscape(err_name);
  responsebody += QStringLiteral("\n                </div>\n                ");
  };
  responsebody += QStringLiteral("              </div>\n            </div>\n            <div class=\"form-group row justify-content-end\">\n              <div class=\"col-lg-10\">\n                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Save</button>\n                <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n              </div>\n            </div>\n          </fieldset>\n        </form>\n      </div>\n    </div>\n  </div>\n</div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(grade_saveView)

#include "grade_saveView.moc"
