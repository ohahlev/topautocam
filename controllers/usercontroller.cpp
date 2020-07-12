#include "usercontroller.h"
#include "user.h"


void UserController::form()
{
    // write code
    userLogout();  // forcibly logged out
    render("form", "login");
}

void UserController::login()
{
    // write code
    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    User user = User::authenticate(username, password);
    if (!user.isNull()) {
        userLogin(&user);
        redirect(url("/admin/dashboard", "index"));
    } else {
        QString message = "Login failed";
        texport(message);
        render("form");
    }
}

void UserController::logout()
{
    // write code
    userLogout();
    redirect(url("/admin/user", "form"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(UserController)
