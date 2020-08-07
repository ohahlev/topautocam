#include "usercontroller.h"
#include "user.h"

void UserController::form()
{
    // write code
    userLogout(); // forcibly logged out
    render("login", "login");
}

void UserController::login()
{
    // write code
    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    User user = User::authenticate(username, password);
    if (!user.isNull())
    {
        userLogin(&user);
        redirect(url("admin/dashboard", "index"));
    }
    else
    {
        QString error = "Login failed";
        texport(error);
        render("login", "login");
    }
}

void UserController::logout()
{
    // write code
    userLogout();
    redirect(url("admin/user", "login"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(UserController)
