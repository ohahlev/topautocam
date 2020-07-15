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

class T_VIEW_EXPORT partial_brandView : public TActionView
{
  Q_OBJECT
public:
  partial_brandView() : TActionView() { }
  QString toString();
};

QString partial_brandView::toString()
{
  responsebody.reserve(345);
  responsebody += QStringLiteral("<a href=\"/\">\n  <!-- <img src=\"/assets/img/demo/logo-header.png\" alt=\"\"> -->\n  <span class=\"ms-logo animated zoomInDown animation-delay-5\">T</span>\n  <h1 class=\"animated fadeInRight animation-delay-6\">TOP <span>AUTO</span></h1>\n  <span class=\"badge-pill badge-pill-pink\">0.0.3b</span>\n</a>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_brandView)

#include "partial_brandView.moc"
