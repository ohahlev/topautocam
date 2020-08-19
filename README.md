# topautocamcpp
this is a website implemented in C++ using framework treefrog.

## framework installation
[treefrog installation](https://www.treefrogframework.org/en/user-guide/install)


## database setup
create user = root, password = root, and run scripts inside folder sql.

to recreate database
```
mysql -uroot -proot < recreate-db.sql
```

to recreate tables
```
mysql -uroot -proot < recreate-tables.sql
```

## qmake
```
qmake +r "CONFIG+=debug"
```

## make
```
make
```

## run
```
treefrog -e dev
```

