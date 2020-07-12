#include <QtCore>
#include <TreeFrogView>
#include "news.h" 
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT news_createView : public TActionView
{
  Q_OBJECT
public:
  news_createView() : TActionView() { }
  QString toString();
};

QString news_createView::toString()
{
  responsebody.reserve(10398);
    tfetch(QVariantMap, news);
  tfetch(QString, err_status);
  tfetch(QString, err_title);
  tfetch(QString, err_subline);
  tfetch(QString, err_line1);
  tfetch(QString, err_line2);
  tfetch(QString, err_line3);
  responsebody += QStringLiteral("<div class=\"container\">\n    <div class=\"row\">\n        <div class=\"col-lg-12\">\n            <div class=\"panel panel-primary\">\n                <div class=\"panel-heading\">\n                    <h3 class=\"panel-title\">\n                        <i class=\"fa fa-globe\"></i>\n                        Create News\n                    </h3>\n                </div>\n                <div class=\"panel-body\">\n                    ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n                    <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/headline/create\">\n                        <fieldset class=\"container\">\n                            <div class=\"form-group row is-empty\">\n                                <label for=\"inputStatus\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Status</label>\n                                <div class=\"col-lg-10\">\n                                    ");
  if(err_status == NULL) {
  responsebody += QStringLiteral("                                        <select class=\"selectpicker form-control is-valid\" id=\"inputStatus\" name=\"news[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["status"]);
  responsebody += QStringLiteral("\">\n                                            <option value=\"PUBLISHED\">PUBLISHED</option>\n                                            <option value=\"UNPUBLISHED\">UNPUBLISHED</option>\n                                        </select>\n                                    ");
  } else {
  responsebody += QStringLiteral("                                        <select class=\"selectpicker form-control is-invalid\" id=\"inputStatus\" name=\"news[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["status"]);
  responsebody += QStringLiteral("\">\n                                            <option value=\"PUBLISHED\">PUBLISHED</option>\n                                            <option value=\"UNPUBLISHED\">UNPUBLISHED</option>\n                                        </select>\n                                        <div class=\"invalid-feedback\">\n                                            ");
  responsebody += THttpUtility::htmlEscape(err_status);
  responsebody += QStringLiteral("\n                                        </div>\n                                    ");
  };
  responsebody += QStringLiteral("                                </div>\n                            </div>\n                            <div class=\"form-group row is-empty\">\n                                <label for=\"inputTitle\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Title</label>\n                                <div class=\"col-lg-10\">\n                                    ");
  if(err_title == NULL) {
  responsebody += QStringLiteral("                                        <input type=\"text\" class=\"editor form-control is-valid\" id=\"inputTitle\" placeholder=\"title\" name=\"news[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["title"]);
  responsebody += QStringLiteral("\"/>\n                                    ");
  } else {
  responsebody += QStringLiteral("                                        <input type=\"text\" class=\"editor form-control is-invalid\" id=\"inputTitle\" placeholder=\"title\" name=\"news[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["title"]);
  responsebody += QStringLiteral("\"/>\n                                        <div class=\"invalid-feedback\">\n                                            ");
  responsebody += THttpUtility::htmlEscape(err_title);
  responsebody += QStringLiteral("\n                                        </div>\n                                    ");
  };
  responsebody += QStringLiteral("                                </div>\n                            </div>\n                            <div class=\"form-group row is-empty\">\n                                <label for=\"inputSubline\" class=\"col-lg-2 control-label\">Subline</label>\n                                <div class=\"col-lg-10\">\n                                    ");
  if(err_subline == NULL) {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputSubline\" class=\"editor form-control is-valid\" placeholder=\"subline\" name=\"news[subline]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["subline"]);
  responsebody += QStringLiteral("\"/>\n                                    ");
  } else {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputSubline\" class=\"editor form-control is-invalid\" placeholder=\"subline\" name=\"news[subline]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["subline"]);
  responsebody += QStringLiteral("\"/>\n                                        <div class=\"invalid-feedback\">\n                                            ");
  responsebody += THttpUtility::htmlEscape(err_subline);
  responsebody += QStringLiteral("\n                                        </div>\n                                    ");
  };
  responsebody += QStringLiteral("                                </div>\n                            </div>\n                            <div class=\"form-group row is-empty\">\n                                <label for=\"inputLine1\" class=\"col-lg-2 control-label\">Line1</label>\n                                <div class=\"col-lg-10\">\n                                    ");
  if(err_line1 == NULL) {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputLine1\" class=\"editor form-control is-valid\" placeholder=\"line1\" name=\"news[line1]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["line1"]);
  responsebody += QStringLiteral("\"/>\n                                    ");
  } else {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputLine1\" class=\"editor form-control is-invalid\" placeholder=\"line1\" name=\"news[line1]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["line1"]);
  responsebody += QStringLiteral("\"/>\n                                        <div class=\"invalid-feedback\">\n                                            ");
  responsebody += THttpUtility::htmlEscape(err_line1);
  responsebody += QStringLiteral("\n                                        </div>\n                                    ");
  };
  responsebody += QStringLiteral("                                </div>\n                            </div>\n                            <div class=\"form-group row is-empty\">\n                                <label for=\"inputLine2\" class=\"col-lg-2 control-label\">Line2</label>\n                                <div class=\"col-lg-10\">\n                                    ");
  if(err_line2 == NULL) {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputLine2\" class=\"editor form-control is-valid\" placeholder=\"line2\" name=\"news[line2]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["line2"]);
  responsebody += QStringLiteral("\"/>\n                                    ");
  } else {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputLine2\" class=\"editor form-control is-invalid\" placeholder=\"line2\" name=\"news[line2]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["line2"]);
  responsebody += QStringLiteral("\"/>\n                                        <div class=\"invalid-feedback\">\n                                            ");
  responsebody += THttpUtility::htmlEscape(err_line2);
  responsebody += QStringLiteral("\n                                        </div>\n                                    ");
  };
  responsebody += QStringLiteral("                                </div>\n                            </div>\n                            <div class=\"form-group row is-empty\">\n                                <label for=\"inputLine3\" class=\"col-lg-2 control-label\">Line3</label>\n                                <div class=\"col-lg-10\">\n                                    ");
  if(err_line3 == NULL) {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputLine3\" class=\"editor form-control is-valid\" placeholder=\"line3\" name=\"news[line3]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["line3"]);
  responsebody += QStringLiteral("\"/>\n                                    ");
  } else {
  responsebody += QStringLiteral("                                        <input type=\"text\" id=\"inputLine3\" class=\"editor form-control is-invalid\" placeholder=\"line3\" name=\"news[line3]\" value=\"");
  responsebody += THttpUtility::htmlEscape(news["line3"]);
  responsebody += QStringLiteral("\"/>\n                                        <div class=\"invalid-feedback\">\n                                            ");
  responsebody += THttpUtility::htmlEscape(err_line3);
  responsebody += QStringLiteral("\n                                        </div>\n                                    ");
  };
  responsebody += QStringLiteral("                                </div>\n                            </div>\n                            <div class=\"form-group row justify-content-end\">\n                                <div class=\"col-lg-10\">\n                                    <button type=\"submit\" class=\"btn btn-raised btn-danger\">Create</button>\n                                    <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n                                </div>\n                            </div>\n                        </fieldset>\n                    </form>\n                </div>\n            </div>\n        </div>\n    </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(news_createView)

#include "news_createView.moc"
