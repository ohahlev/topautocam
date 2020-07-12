#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_part_adminView : public TActionView
{
  Q_OBJECT
public:
  partial_part_adminView() : TActionView() { }
  QString toString();
};

QString partial_part_adminView::toString()
{
  responsebody.reserve(3885);
  responsebody += QStringLiteral("<div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n  <div class=\"card\">\n    <figure class=\"ms-thumbnail\">\n      <img src=\"/img/demo/port2.jpg\" alt=\"\" class=\"img-fluid\">\n      <figcaption class=\"ms-thumbnail-caption text-center\">\n        <div class=\"ms-thumbnail-caption-content\">\n          <h4 class=\"ms-thumbnail-caption-title mb-2\">PART1</h4>\n          <a href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\" \n          data-toggle=\"modal\" data-target=\"#editPartModal\">\n            <i class=\"zmdi zmdi-edit\"></i>\n          </a>\n          <a href=href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removePartModal\">\n            <i class=\"zmdi zmdi-delete\"></i>\n          </a>\n        </div>\n      </figcaption>\n    </figure>\n    <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n      <h3 class=\"color-primary no-mt\">actions</h3>\n      <p>here it is</p>\n    </div>\n  </div>\n</div>\n<div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n  <div class=\"card\">\n    <figure class=\"ms-thumbnail\">\n      <img src=\"/img/demo/port2.jpg\" alt=\"\" class=\"img-fluid\">\n      <figcaption class=\"ms-thumbnail-caption text-center\">\n        <div class=\"ms-thumbnail-caption-content\">\n          <h4 class=\"ms-thumbnail-caption-title mb-2\">PART2</h4>\n          <a href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\" \n          data-toggle=\"modal\" data-target=\"#editPartModal\">\n            <i class=\"zmdi zmdi-edit\"></i>\n          </a>\n          <a href=href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removePartModal\">\n            <i class=\"zmdi zmdi-delete\"></i>\n          </a>\n        </div>\n      </figcaption>\n    </figure>\n    <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n      <h3 class=\"color-primary no-mt\">actions</h3>\n      <p>here it is</p>\n    </div>\n  </div>\n</div>\n<div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n  <div class=\"card\">\n    <figure class=\"ms-thumbnail\">\n      <img src=\"/img/demo/port2.jpg\" alt=\"\" class=\"img-fluid\">\n      <figcaption class=\"ms-thumbnail-caption text-center\">\n        <div class=\"ms-thumbnail-caption-content\">\n          <h4 class=\"ms-thumbnail-caption-title mb-2\">PART3</h4>\n          <a href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\" \n          data-toggle=\"modal\" data-target=\"#editPartModal\">\n            <i class=\"zmdi zmdi-edit\"></i>\n          </a>\n          <a href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removePartModal\">\n            <i class=\"zmdi zmdi-delete\"></i>\n          </a>\n        </div>\n      </figcaption>\n    </figure>\n    <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n      <h3 class=\"color-primary no-mt\">actions</h3>\n      <p>here it is</p>\n    </div>\n  </div>\n</div>\n\n");
  responsebody += QVariant(renderPartial("part_admin_form_edit")).toString();
  responsebody += QStringLiteral("\n");
  responsebody += QVariant(renderPartial("part_admin_remove")).toString();

  return responsebody;
}

T_DEFINE_VIEW(partial_part_adminView)

#include "partial_part_adminView.moc"
