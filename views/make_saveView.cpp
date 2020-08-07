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

class T_VIEW_EXPORT make_saveView : public TActionView
{
  Q_OBJECT
public:
  make_saveView() : TActionView() { }
  QString toString();
};

QString make_saveView::toString()
{
  responsebody.reserve(5133);
    tfetch(QVariantMap, make);
  tfetch(QString, err_name);
  tfetch(QString, err_logo);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <i class=\"fa fa-globe\"></i> Edit Make\n          </h3>\n        </div>\n        <div class=\"panel-body\">\n          <div class=\"card\">\n            <div class=\"card-body mx-auto\">\n              <a href=\"");
  responsebody += THttpUtility::htmlEscape(make["logo"]);
  responsebody += QStringLiteral("\" data-lightbox=\"");
  responsebody += THttpUtility::htmlEscape(make["name"]);
  responsebody += QStringLiteral("\" data-title=\"");
  responsebody += THttpUtility::htmlEscape(make["name"]);
  responsebody += QStringLiteral("\" class=\"img-thumbnail withripple\">\n                <div class=\"thumbnail-container\" style=\"width: 300px;\">\n                  <img src=\"");
  responsebody += THttpUtility::htmlEscape(make["logo"]);
  responsebody += QStringLiteral("\" class=\"img-fluid\">\n                </div>\n                <div class=\"ripple-container\"></div>\n              </a>\n            </div>\n          </div>\n          ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/make/save/");
  responsebody += THttpUtility::htmlEscape(make["id"]);
  responsebody += QStringLiteral("\" enctype=\"multipart/form-data\">\n            <input type=\"text\" name=\"make[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(make["id"]);
  responsebody += QStringLiteral("\" style=\"display: none\"/>\n              <fieldset class=\"container\">\n                <div class=\"form-group row is-empty\">\n                  <label for=\"inputName\" autocomplete=\"false\" \n        class=\"col-lg-2 control-label\">Name</label>\n                  <div class=\"col-lg-10\">\n                    ");
  if(err_name == NULL) {
  responsebody += QStringLiteral("                      <input type=\"text\" class=\"form-control is-valid\" id=\"inputName\" placeholder=\"name\" name=\"make[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(make["name"]);
  responsebody += QStringLiteral("\" />\n                      ");
  } else {
  responsebody += QStringLiteral("                      <input type=\"text\" class=\"form-control is-invalid\" id=\"inputName\" placeholder=\"name\" name=\"make[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(make["name"]);
  responsebody += QStringLiteral("\" />\n                      <div class=\"invalid-feedback\">\n                        ");
  responsebody += THttpUtility::htmlEscape(err_name);
  responsebody += QStringLiteral("\n                      </div>\n                      ");
  };
  responsebody += QStringLiteral("                    </div>\n                  </div>\n                  <div class=\"form-group row is-empty\">\n                    <label for=\"inputLogo\" class=\"col-lg-2 control-label\">Logo</label>\n                    <div class=\"col-lg-10\">\n                      ");
  if(err_logo == NULL) {
  responsebody += QStringLiteral("                        <input type=\"text\" readonly=\"\" name=\"make[logo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(make["logo"]);
  responsebody += QStringLiteral("\" class=\"form-control is-valid\" placeholder=\"Browse...\">\n                        <input type=\"file\" id=\"inputLogo\" name=\"logo\" class=\"form-control\" />\n                        ");
  } else {
  responsebody += QStringLiteral("                        <input type=\"text\" readonly=\"\" name=\"make[logo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(make["logo"]);
  responsebody += QStringLiteral("\" class=\"form-control is-invalid\" placeholder=\"Browse...\">\n                        <input type=\"file\" id=\"inputLogo\" name=\"logo\" class=\"form-control\" />\n                        <div class=\"invalid-feedback\">\n                          ");
  responsebody += THttpUtility::htmlEscape(err_logo);
  responsebody += QStringLiteral("\n                        </div>\n                        ");
  };
  responsebody += QStringLiteral("                      </div>\n                    </div>\n                    <div class=\"form-group row justify-content-end\">\n                      <div class=\"col-lg-10\">\n                        <button type=\"submit\" class=\"btn btn-raised btn-danger\">Save</button>\n                        <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n                      </div>\n                    </div>\n                  </fieldset>\n                </form>\n              </div>\n            </div>\n          </div>\n        </div>\n      </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(make_saveView)

#include "make_saveView.moc"
