#include "applicationcontroller.h"
#include "news.h"
#include "newsgallery.h"

ApplicationController::ApplicationController()
    : TActionController()
{
    auto newsList = News::getAllPublished();
    texport(newsList);

    auto newsGalleryList = NewsGallery::getAll();
    texport(newsGalleryList);
}

ApplicationController::~ApplicationController()
{
}

void ApplicationController::staticInitialize()
{
}

void ApplicationController::staticRelease()
{
}

bool ApplicationController::preFilter()
{
    return true;
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApplicationController)
