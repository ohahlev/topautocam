#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_model_resultView : public TActionView
{
  Q_OBJECT
public:
  partial_model_resultView() : TActionView() { }
  QString toString();
};

QString partial_model_resultView::toString()
{
  responsebody.reserve(5161);
  responsebody += QStringLiteral("<div class=\"panel panel-primary\">\n  <div class=\"panel-heading\">\n    <h3 class=\"panel-title\">\n      <a href=\"javascript:void(0)\" class=\"btn-circle btn-circle-raised btn-circle-danger float-right\" \n      data-toggle=\"modal\" data-target=\"#newModelModal\">\n        <i class=\"fa fa-plus\" style=\"margin-left: 10px\"></i>\n      </a>\n      <i class=\"fa fa-globe\"></i> Model Management\n    </h3>\n  </div>\n  <div class=\"panel-body\">\n    <div class=\"row\" id=\"Container\">\n      <div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n        <div class=\"card\">\n          <figure class=\"ms-thumbnail\">\n            <img src=\"/img/demo/port2.jpg\" alt=\"\" class=\"img-fluid\">\n            <figcaption class=\"ms-thumbnail-caption text-center\">\n              <div class=\"ms-thumbnail-caption-content\">\n                <h4 class=\"ms-thumbnail-caption-title mb-2\">Alphard1</h4>\n                <a href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\" \n          data-toggle=\"modal\" data-target=\"#editModelModal\">\n                  <i class=\"zmdi zmdi-edit\"></i>\n                </a>\n                <a href=href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removeModelModal\">\n                  <i class=\"zmdi zmdi-delete\"></i>\n                </a>\n              </div>\n            </figcaption>\n          </figure>\n          <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n            <h3 class=\"color-primary no-mt\">actions</h3>\n            <p>here it is</p>\n          </div>\n        </div>\n      </div>\n      <div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n        <div class=\"card\">\n          <figure class=\"ms-thumbnail\">\n            <img src=\"/img/demo/port2.jpg\" alt=\"\" class=\"img-fluid\">\n            <figcaption class=\"ms-thumbnail-caption text-center\">\n              <div class=\"ms-thumbnail-caption-content\">\n                <h4 class=\"ms-thumbnail-caption-title mb-2\">Alphard2</h4>\n                <a href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\" \n          data-toggle=\"modal\" data-target=\"#editModelModal\">\n                  <i class=\"zmdi zmdi-edit\"></i>\n                </a>\n                <a href=href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removeModelModal\">\n                  <i class=\"zmdi zmdi-delete\"></i>\n                </a>\n              </div>\n            </figcaption>\n          </figure>\n          <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n            <h3 class=\"color-primary no-mt\">actions</h3>\n            <p>here it is</p>\n          </div>\n        </div>\n      </div>\n      <div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n        <div class=\"card\">\n          <figure class=\"ms-thumbnail\">\n            <img src=\"/img/demo/port2.jpg\" alt=\"\" class=\"img-fluid\">\n            <figcaption class=\"ms-thumbnail-caption text-center\">\n              <div class=\"ms-thumbnail-caption-content\">\n                <h4 class=\"ms-thumbnail-caption-title mb-2\">Alphard3</h4>\n                <a href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\" \n          data-toggle=\"modal\" data-target=\"#editModelModal\">\n                  <i class=\"zmdi zmdi-edit\"></i>\n                </a>\n                <a href=href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removeModelModal\">\n                  <i class=\"zmdi zmdi-delete\"></i>\n                </a>\n              </div>\n            </figcaption>\n          </figure>\n          <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n            <h3 class=\"color-primary no-mt\">actions</h3>\n            <p>here it is</p>\n          </div>\n        </div>\n      </div>\n    </div>\n    <div class=\"row\">\n      <div class=\"col-lg-3\">\n        ");
  responsebody += QVariant(renderPartial("pager")).toString();
  responsebody += QStringLiteral("\n      </div>\n    </div>\n  </div>\n</div>\n");
  responsebody += QVariant(renderPartial("model_form_new")).toString();
  responsebody += QStringLiteral("\n");
  responsebody += QVariant(renderPartial("model_form_edit")).toString();
  responsebody += QStringLiteral("\n");
  responsebody += QVariant(renderPartial("model_remove")).toString();
  responsebody += QStringLiteral("\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_model_resultView)

#include "partial_model_resultView.moc"
