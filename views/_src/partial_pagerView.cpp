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

class T_VIEW_EXPORT partial_pagerView : public TActionView
{
  Q_OBJECT
public:
  partial_pagerView() : TActionView() { }
  QString toString();
};

QString partial_pagerView::toString()
{
  responsebody.reserve(422);
  responsebody += tr("<nav aria-label=\"...\">\n    <ul class=\"pager pager-flat pager-danger d-flex justify-content-between\">\n        <li class=\"page-item\"><a class=\"page-link\" href=\"javascript:void(0)\"><span aria-hidden=\"true\">«</span> Previous</a></li>\n        <li class=\"page-item\"><a class=\"page-link\" href=\"javascript:void(0)\">Next <span aria-hidden=\"true\">»</span></a></li>\n    </ul>\n</nav>");

  return responsebody;
}

T_DEFINE_VIEW(partial_pagerView)

#include "partial_pagerView.moc"
