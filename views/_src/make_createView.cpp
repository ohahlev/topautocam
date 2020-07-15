#include <QtCore>
#include <TreeFrogView>
#include "make.h" 
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

class T_VIEW_EXPORT make_createView : public TActionView
{
  Q_OBJECT
public:
  make_createView() : TActionView() { }
  QString toString();
};

QString make_createView::toString()
{
  responsebody.reserve(3619);
    tfetch(QVariantMap, make);
  tfetch(QString, err_name);
  tfetch(QString, err_logo);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <i class=\"fa fa-globe\"></i> Create Make\n          </h3>\n        </div>\n        <div class=\"panel-body\">\n          ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n          <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/make/create\" enctype=\"multipart/form-data\">\n            <fieldset class=\"container\">\n              <div class=\"form-group row is-empty\">\n                <label for=\"inputName\" autocomplete=\"false\" \n        class=\"col-lg-2 control-label\">Name</label>\n                <div class=\"col-lg-10\">\n                  ");
  if(err_name == NULL) {
  responsebody += QStringLiteral("                    <input type=\"text\" class=\"form-control is-valid\" id=\"inputName\" placeholder=\"name\" name=\"make[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(make["name"]);
  responsebody += QStringLiteral("\" />\n                    ");
  } else {
  responsebody += QStringLiteral("                    <input type=\"text\" class=\"form-control is-invalid\" id=\"inputName\" placeholder=\"name\" name=\"make[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(make["name"]);
  responsebody += QStringLiteral("\" />\n                    <div class=\"invalid-feedback\">\n                      ");
  responsebody += THttpUtility::htmlEscape(err_name);
  responsebody += QStringLiteral("\n                    </div>\n                    ");
  };
  responsebody += QStringLiteral("                  </div>\n                </div>\n                <div class=\"form-group row is-empty\">\n                  <label for=\"inputLogo\" class=\"col-lg-2 control-label\">Logo</label>\n                  <div class=\"col-lg-10\">\n                    ");
  if(err_logo == NULL) {
  responsebody += QStringLiteral("                      <input type=\"text\" readonly=\"\" name=\"make[logo]\" class=\"form-control is-valid\" placeholder=\"Browse...\">\n                      <input type=\"file\" id=\"inputLogo\" name=\"logo\" class=\"form-control\" />\n                      ");
  } else {
  responsebody += QStringLiteral("                      <input type=\"text\" readonly=\"\" name=\"make[logo]\" class=\"form-control is-invalid\" placeholder=\"Browse...\">\n                      <input type=\"file\" id=\"inputLogo\" name=\"logo\" class=\"form-control\" />\n                      <div class=\"invalid-feedback\">\n                        ");
  responsebody += THttpUtility::htmlEscape(err_logo);
  responsebody += QStringLiteral("\n                      </div>\n                      ");
  };
  responsebody += QStringLiteral("                    </div>\n                  </div>\n                  <div class=\"form-group row justify-content-end\">\n                    <div class=\"col-lg-10\">\n                      <button type=\"submit\" class=\"btn btn-raised btn-danger\">Create</button>\n                      <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n                    </div>\n                  </div>\n                </fieldset>\n              </form>\n            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(make_createView)

#include "make_createView.moc"
