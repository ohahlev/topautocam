#include <QtCore>
#include <TreeFrogView>
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

class T_VIEW_EXPORT partial_vehicle_detailView : public TActionView
{
  Q_OBJECT
public:
  partial_vehicle_detailView() : TActionView() { }
  QString toString();
};

QString partial_vehicle_detailView::toString()
{
  responsebody.reserve(1125);
  responsebody += QStringLiteral("<div class=\"col-xl-3 col-lg-4 col-sm-6 mix laptop apple\" data-price=\"1999.99\" data-date=\"20160901\">\n  <div class=\"card\">\n    <div class=\"card-body overflow-hidden text-center\">\n      <a href=\"ecommerce-item.html\"><img src=\"/img/demo/products/macbook.png\" alt=\"\" class=\"img-fluid center-block\"></a>\n      <h4 class=\"text-normal text-center\">Macbook Pro 2015</h4>\n      <p>Quibusdam aperiam tempora ut blanditiis cumque ab pariatur.</p>\n      <div class=\"mt-2\">\n        <span class=\"mr-2\">\n          <i class=\"zmdi zmdi-star color-warning\"></i>\n          <i class=\"zmdi zmdi-star color-warning\"></i>\n          <i class=\"zmdi zmdi-star color-warning\"></i>\n          <i class=\"zmdi zmdi-star color-warning\"></i>\n          <i class=\"zmdi zmdi-star\"></i>\n        </span>\n        <span class=\"ms-tag ms-tag-success\">$ 1999.99</span>\n      </div>\n      <a href=\"javascript:void(0)\" class=\"btn btn-primary btn-sm btn-block btn-raised mt-2 no-mb\"><i class=\"zmdi zmdi-shopping-cart-plus\"></i> Add to Cart</a>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_vehicle_detailView)

#include "partial_vehicle_detailView.moc"
