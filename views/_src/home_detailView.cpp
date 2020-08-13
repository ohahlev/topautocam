#include <QtCore>
#include <TreeFrogView>
#include "vehicle.h" 
#include "vehiclegallery.h" 
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

class T_VIEW_EXPORT home_detailView : public TActionView
{
  Q_OBJECT
public:
  home_detailView() : TActionView() { }
  QString toString();
};

QString home_detailView::toString()
{
  responsebody.reserve(6203);
      tfetch(Vehicle, vehicle);
  tfetch(QList<VehicleGallery>, vehicleGalleryList);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"card card-body animated zoomInDown animation-delay-5\">\n      <h2>");
  responsebody += QVariant(vehicle.title()).toString();
  responsebody += QStringLiteral("</h2>\n      <div class=\"mb-2 mt-4\">\n        <div class=\"row\">\n          <div class=\"col-sm-6\">\n            <span class=\"mr-2\">\n              <i class=\"zmdi zmdi-hc-lg zmdi-star color-warning\"></i>\n              <i class=\"zmdi zmdi-hc-lg zmdi-star color-warning\"></i>\n              <i class=\"zmdi zmdi-hc-lg zmdi-star color-warning\"></i>\n              <i class=\"zmdi zmdi-hc-lg zmdi-star color-warning\"></i>\n              <i class=\"zmdi zmdi-hc-lg zmdi-star\"></i>\n            </span>\n          </div>\n          <div class=\"col-sm-6 text-center\">\n            <h2 class=\"color-success no-m text-normal\">");
  responsebody += QVariant(vehicle.price()).toString();
  responsebody += QStringLiteral("</h2>\n          </div>\n        </div>\n        <!--- row -->\n      </div>\n      <!-- mb-2 -->\n      <p class=\"lead\">\n        ");
  responsebody += QVariant(vehicle.detail()).toString();
  responsebody += QStringLiteral("\n      </p>\n      <ul class=\"list-unstyled\">\n        <li><strong>");
  responsebody += QVariant(vehicle.getModel().name()).toString();
  responsebody += QStringLiteral("</strong></li>\n      </li>\n      <li class=\"mb-2\"><strong>Availability: </strong>\n        ");
  if (vehicle.inventoryStatus() == "SOLD") {
  responsebody += QStringLiteral("          <span class=\"ms-tag ms-tag-danger\">\n            SOLD\n          </span>\n          ");
  } else {
  responsebody += QStringLiteral("          <span class=\"ms-tag ms-tag-success\">$\n            ");
  responsebody += QVariant(vehicle.price()).toString();
  responsebody += QStringLiteral("\n          </span>\n          ");
  };
  responsebody += QStringLiteral("        </li>\n      </ul>\n    </div>\n    <!-- card -->\n  </div>\n  <!-- row -->\n  <div class=\"row\">\n    ");
  for (const auto &i : vehicleGalleryList) {
  responsebody += QStringLiteral("      <div class=\"col-md-4 card card-body animated zoomInDown animation-delay-5\">\n        <img src=\"");
  responsebody += QVariant(i.photo()).toString();
  responsebody += QStringLiteral("\" alt=\"\" class=\"img-fluid center-block\" />\n      </div>\n      ");
  };
  responsebody += QStringLiteral("    </div>\n    <!-- row -->\n    <h2 class=\"mt-4 mb-4 right-line\">Related Products</h2>\n    <div class=\"row\">\n      <div class=\"col-md-4\">\n        <div class=\"card ms-feature wow zoomInUp animation-delay-3\">\n          <div class=\"card-body overflow-hidden text-center\">\n            <a href=\"javascript:void(0)\"><img src=\"assets/img/demo/products/surfaceBook.png\" alt=\"\" class=\"img-fluid center-block\"></a>\n            <h4 class=\"text-normal text-center\">Microsoft Surface Book</h4>\n            <p>Quibusdam aperiam tempora ut blanditiis cumque ab pariatur.</p>\n            <div class=\"mt-2\">\n              <span class=\"mr-2\">\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star\"></i>\n              </span>\n              <span class=\"ms-tag ms-tag-success\">$ 2499.25</span>\n            </div>\n            <a href=\"javascript:void(0)\" class=\"btn btn-primary btn-sm btn-block btn-raised mt-2 no-mb\"><i class=\"zmdi zmdi-shopping-cart-plus\"></i> Add to Cart</a>\n          </div>\n        </div>\n      </div>\n      <div class=\"col-md-4\">\n        <div class=\"card ms-feature wow zoomInUp animation-delay-5\">\n          <div class=\"card-body overflow-hidden text-center\">\n            <a href=\"javascript:void(0)\"><img src=\"assets/img/demo/products/ipad.png\" alt=\"\" class=\"img-fluid center-block\"></a>\n            <h4 class=\"text-normal text-center\">iPad Pro</h4>\n            <p>Quibusdam aperiam tempora ut blanditiis cumque ab pariatur.</p>\n            <div class=\"mt-2\">\n              <span class=\"mr-2\">\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n              </span>\n              <span class=\"ms-tag ms-tag-success\">$ 999.99</span>\n            </div>\n            <a href=\"javascript:void(0)\" class=\"btn btn-primary btn-sm btn-block btn-raised mt-2 no-mb\"><i class=\"zmdi zmdi-shopping-cart-plus\"></i> Add to Cart</a>\n          </div>\n        </div>\n      </div>\n      <div class=\"col-md-4\">\n        <div class=\"card ms-feature wow zoomInUp animation-delay-7\">\n          <div class=\"card-body overflow-hidden text-center\">\n            <a href=\"javascript:void(0)\"><img src=\"assets/img/demo/products/galaxyTab.png\" alt=\"\" class=\"img-fluid center-block\"></a>\n            <h4 class=\"text-normal text-center\">Galaxy Tab S2</h4>\n            <p>Quibusdam aperiam tempora ut blanditiis cumque ab pariatur.</p>\n            <div class=\"mt-2\">\n              <span class=\"mr-2\">\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star color-warning\"></i>\n                <i class=\"zmdi zmdi-star\"></i>\n              </span>\n              <span class=\"ms-tag ms-tag-success\">$ 538.99</span>\n            </div>\n            <a href=\"javascript:void(0)\" class=\"btn btn-primary btn-sm btn-block btn-raised mt-2 no-mb\"><i class=\"zmdi zmdi-shopping-cart-plus\"></i> Add to Cart</a>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(home_detailView)

#include "home_detailView.moc"
