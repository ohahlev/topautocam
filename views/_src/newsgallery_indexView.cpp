#include <QtCore>
#include <TreeFrogView>
#include "newsgallery.h"
#include "newsgallery.h"
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT newsgallery_indexView : public TActionView
{
  Q_OBJECT
public:
  newsgallery_indexView() : TActionView() { }
  QString toString();
};

QString newsgallery_indexView::toString()
{
  responsebody.reserve(7922);
    tfetch(QString, notice);
  responsebody += QStringLiteral("<div class=\"container\">\n    <div class=\"row\">\n        <div class=\"col-lg-12\">\n            <div class=\"panel panel-primary\">\n                <div class=\"panel-heading\">\n                    <h3 class=\"panel-title\">\n                        <i class=\"fa fa-globe\"></i>\n                        News Gallery\n                    </h3>\n                </div>\n                <div class=\"panel-body\">\n                    <div class=\"card row ml-1 mr-1\">\n                        <div class=\"card-body\">\n                            ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n                            ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n                            <form class=\"form-horizontal\" method=\"POST\" action=\"gallery/upload\" enctype=\"multipart/form-data\">\n                                <fieldset class=\"container\">\n                                    <div class=\"form-group row\">\n                                        <label for=\"inputFile\" class=\"col-lg-2 control-label\">Files</label>\n                                        <div class=\"col-lg-10\">\n                                            <input type=\"text\" readonly=\"\" class=\"form-control\" placeholder=\"Browse...\"/>\n                                            <input type=\"file\" name=\"picture[]\" id=\"inputFile\" multiple=\"\"/>\n                                        </div>\n                                    </div>\n                                    <div class=\"form-group row\">\n                                        <div class=\"col-lg-2\"></div>\n                                        <div class=\"col-lg-10\">\n                                            <input type=\"submit\" class=\"btn btn-raised btn-royal\" value=\"upload\"/>\n                                        </div>\n                                    </div>\n                                </fieldset>\n                            </form>\n                        </div>\n                    </div>\n                    ");
    responsebody += QStringLiteral("                    <div class=\"row\">\n                        ");
  tfetch(QList<NewsGallery>, newsGallery);
  responsebody += QStringLiteral("                        ");
  for (const auto &i : newsGallery) {
  responsebody += QStringLiteral("                            <div class=\"col-md-4 py-4\">\n                                <div class=\"thumbnail-container\">\n                                    <figure class=\"ms-thumbnail\">\n                                        <img src=\"");
  responsebody += QVariant(i.image()).toString();
  responsebody += QStringLiteral("\" alt=\"...\" class=\"img-fluid\">\n                                            <figcaption class=\"ms-thumbnail-caption text-center\">\n                                                <div class=\"ms-thumbnail-caption-content\">\n                                                    <a href=\"href=\" javascript:void(0)\"\" class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\" data-toggle=\"modal\" data-target=\"#removeNewsGalleryModal");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                                                        <i class=\"zmdi zmdi-delete\"></i>\n                                                    </a>\n                                                </div>\n                                            </figcaption>\n                                        </figure>\n                                    </div>\n                                    <div class=\"ripple-container\"></div>\n                                </a>\n                            </div>\n                            <!-- remove modal -->\n                            <div class=\"modal modal-danger\" id=\"removeNewsGalleryModal");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"removeNewsGalleryModalLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                                <div class=\"modal-dialog modal-lg animated zoomIn animated-3x\" role=\"document\">\n                                    <div class=\"modal-content\">\n                                        <div class=\"modal-header\">\n                                            <h3 class=\"modal-title color-secondary\" id=\"removeNewsGalleryModalLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">Remove News</h3>\n                                        </div>\n                                        <div class=\"modal-body\">\n\n                                            <div class=\"card\">\n                                                <div class=\"card-body mx-auto\">\n                                                    <a href=\"");
  responsebody += THttpUtility::htmlEscape(i.image());
  responsebody += QStringLiteral("\" data-lightbox=\"");
  responsebody += THttpUtility::htmlEscape(i.image());
  responsebody += QStringLiteral("\" data-title=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" class=\"img-thumbnail withripple\">\n                                                        <div class=\"thumbnail-container\" style=\"width: 300px;\">\n                                                            <img src=\"");
  responsebody += THttpUtility::htmlEscape(i.image());
  responsebody += QStringLiteral("\" class=\"img-fluid\"></div>\n                                                            <div class=\"ripple-container\"></div>\n                                                        </a>\n                                                    </div>\n                                                </div>\n                                                <form class=\"form-horizontal\" method=\"POST\" action=\"gallery/remove/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                                                    <fieldset class=\"container\">\n                                                        <div class=\"form-group row\">\n                                                            <div class=\"col-lg-10\">\n                                                                <h3>Are you sure to remove this news gallery image?</h3>\n                                                            </div>\n                                                        </div>\n                                                        <div class=\"form-group row\">\n                                                            <div class=\"col-lg-10\">\n                                                                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Yes</button>\n                                                                <button type=\"button\" class=\"btn btn-primary\" data-dismiss=\"modal\">No</button>\n                                                            </div>\n                                                        </div>\n                                                    </fieldset>\n                                                </form>\n                                            </div>\n                                        </div>\n                                    </div>\n                                </div>\n                            ");
  };
  responsebody += QStringLiteral("                        </div>\n                    </div>\n                </div>\n            </div>\n        </div>\n    </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(newsgallery_indexView)

#include "newsgallery_indexView.moc"
