
USE topautocambodiadb;

DROP TABLE IF EXISTS blog;

DROP TABLE IF EXISTS news;
DROP TABLE IF EXISTS news_gallery;

DROP TABLE IF EXISTS vehicle_offer;
DROP TABLE IF EXISTS vehicle_gallery;
DROP TABLE IF EXISTS vehicle;
DROP TABLE IF EXISTS part_gallery;
DROP TABLE IF EXISTS part_offer;
DROP TABLE IF EXISTS part;
DROP TABLE IF EXISTS make;
DROP TABLE IF EXISTS model;
DROP TABLE IF EXISTS vehicle_model;
DROP TABLE IF EXISTS color;
DROP TABLE IF EXISTS grade;
DROP TABLE IF EXISTS drive_type;
DROP TABLE IF EXISTS body_type;
DROP TABLE IF EXISTS fuel_type;
DROP TABLE IF EXISTS user;

CREATE TABLE user ( username VARCHAR(128) PRIMARY KEY, password VARCHAR(128) );
INSERT INTO user (username, password) VALUES
    ('admin1', 'admin1'),
    ('admin2', PASSWORD('admin2'));


CREATE TABLE blog (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(32) NOT NULL,
    body TEXT NOT NULL,
    lock_revision INTEGER NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

CREATE TABLE news (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(1024) NOT NULL,
    subline VARCHAR(1024) NOT NULL,
    status ENUM('PUBLISHED','UNPUBLISHED') DEFAULT 'UNPUBLISHED',
    line1 VARCHAR(1024) NOT NULL,
    line2 VARCHAR(1024) NOT NULL,
    line3 VARCHAR(1024) NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO news(title, subline, line1, line2, line3, status) VALUES 
    ('<strong>TOP AUTO</strong> CAMBODIA', 
    'the most <span class="color-danger">reliable</span> car sellers', 
    'directly import car from oversea',
    'genuine part supply',
    'registered and licensed',
    'PUBLISHED'
    ),
    ('Everyone can <strong>test drive</strong>', 
    'test drive until you <span class="color-warning">satisfy</span>',
    'test drive for many rounds',
    'test drive to prove its quality',
    'we dare you to come and test drive',
    'PUBLISHED'
    ),
    ('Anyone can have a <strong>car</strong>', 
    'many <span class="color-danger">payment</span> plans are available ',
    'owning a car is no longer difficult',
    'good relationship with the banks',
    'lowest interest rate ever',
    'PUBLISHED'
    );

CREATE TABLE news_gallery (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    image VARCHAR(64) NOT NULL,
    status ENUM('PUBLISHED','UNPUBLISHED') DEFAULT 'UNPUBLISHED',
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO news_gallery (image, status) VALUES 
('/media/news/alphard1.jpg', 'PUBLISHED'),
('/media/news/alphard2.jpg', 'PUBLISHED'),
('/media/news/alphard3.jpg', 'PUBLISHED');

CREATE TABLE make (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    logo VARCHAR(32) NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO make(name, logo) VALUES 
    ('TOYOTA', '/media/make/toyota.png'),
    ('LEXUS', '/media/make/lexus.png');
    
CREATE TABLE vehicle_model (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    logo VARCHAR(32) NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO vehicle_model(name, logo) VALUES
    ('ALPHARD', '/media/model/alphard.jpg'),
    ('LEXUS330', '/media/model/lexus330.jpg');

CREATE TABLE color (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO color(name) VALUES('WHITE'), ('BLACK');

CREATE TABLE grade (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO grade(name) VALUES ('A'), ('B'), ('C');

CREATE TABLE drive_type (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO drive_type(name) VALUES('4WD'), ('FWD'), ('AWD');

CREATE TABLE body_type (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO body_type(name) VALUES('SEDAN'), ('SUV'), ('WAGON');

CREATE TABLE fuel_type (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW()
) DEFAULT CHARSET=utf8;

INSERT INTO fuel_type(name) VALUES('GASOLINE'), ('DIESEL');

CREATE TABLE vehicle (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(32) NOT NULL,
    detail VARCHAR(10240) NOT NULL,
    code VARCHAR(32) NOT NULL UNIQUE,
    frame_no VARCHAR(64) NOT NULL UNIQUE,
    manufacturing_date DATETIME NOT NULL,
    deposit_date DATETIME NOT NULL,
    
    engine VARCHAR(32) NOT NULL,
    mileage VARCHAR(32) NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),

    vehicle_status ENUM('OLD', 'NEW') DEFAULT 'OLD',
    inventory_status ENUM('SOLD', 'STOCKED') DEFAULT 'STOCKED',

    price DECIMAL(10,2),

    make_id  INTEGER NOT NULL,
    model_id INTEGER NOT NULL,
    color_id INTEGER NOT NULL,
    grade_id INTEGER NOT NULL,
    drive_id INTEGER NOT NULL,
    fuel_id  INTEGER NOT NULL,
    body_id  INTEGER NOT NULL,

    FOREIGN KEY (make_id)  REFERENCES make(id) ON DELETE CASCADE,
    FOREIGN KEY (model_id) REFERENCES vehicle_model(id) ON DELETE CASCADE,
    FOREIGN KEY (color_id) REFERENCES color(id) ON DELETE CASCADE,
    FOREIGN KEY (grade_id) REFERENCES grade(id) ON DELETE CASCADE,
    FOREIGN KEY (drive_id) REFERENCES drive_type(id) ON DELETE CASCADE,
    FOREIGN KEY (body_id)  REFERENCES body_type(id) ON DELETE CASCADE,
    FOREIGN KEY (fuel_id)  REFERENCES fuel_type(id) ON DELETE CASCADE

) DEFAULT CHARSET=utf8;

INSERT INTO vehicle(title, detail, code, frame_no, manufacturing_date, deposit_date, engine, mileage, 
    vehicle_status, inventory_status, price, make_id, model_id, color_id, grade_id, drive_id, fuel_id, body_id
) VALUES 
('best vhicle','this best vehicle and no joke', 'CODE-A', 'FRAME-A', '2020-05-23 20:46:13', '2020-05-23 20:46:13', '3000HP', '344MPH', 'OLD', 'SOLD', 15000, 1, 1, 1, 1, 1, 1, 1),
('cheapest and good one', 'come and buy this beast, guarantee it is good', 'CODE-B', 'FRAME-B', '2020-05-20 20:46:13', '2020-05-20 20:46:13', '3300HP', '400MPH', 'NEW', 'STOCKED', 20000, 2, 2, 2, 2, 2, 2, 2),
('very durable, king offroad', 'offroading...', 'CODE-C', 'FRAME-C', '2020-05-20 20:46:13', '2020-05-20 20:46:13', '3300HP', '400MPH', 'OLD', 'STOCKED', 10000, 1, 1, 1, 1, 1, 1, 1);

CREATE TABLE vehicle_gallery (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    photo VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),
    vehicle_id INTEGER NOT NULL,
    FOREIGN KEY (vehicle_id) REFERENCES vehicle(id) ON DELETE CASCADE
) DEFAULT CHARSET=utf8;

INSERT INTO vehicle_gallery (photo, vehicle_id) VALUES 
('/media/vehicle/1/1.jpg', 1),
('/media/vehicle/1/2.jpg', 1),
('/media/vehicle/1/3.jpg', 1),
('/media/vehicle/1/4.jpg', 1),
('/media/vehicle/1/5.jpg', 1),
('/media/vehicle/1/6.jpg', 1),
('/media/vehicle/1/7.jpg', 1),
('/media/vehicle/1/8.jpg', 1),
('/media/vehicle/1/9.jpg', 1),
('/media/vehicle/1/10.jpg', 1),
('/media/vehicle/2/1.jpg', 2),
('/media/vehicle/2/2.jpg', 2),
('/media/vehicle/2/3.jpg', 2),
('/media/vehicle/2/4.jpg', 2),
('/media/vehicle/2/5.jpg', 2);

CREATE TABLE part (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    code VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),
    detail VARCHAR(1024),
    make_id INTEGER NOT NULL,
    FOREIGN KEY (make_id) REFERENCES make(id)
) DEFAULT CHARSET=utf8;

CREATE TABLE part_gallery (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(32) NOT NULL UNIQUE,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),
    part_id INTEGER NOT NULL,
    FOREIGN KEY (part_id) REFERENCES part(id) ON DELETE CASCADE
) DEFAULT CHARSET=utf8;

CREATE TABLE vehicle_offer (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    discount DECIMAL(5,2) NOT NULL,
    status ENUM('ACTIVE', 'INACTIVE') DEFAULT 'INACTIVE',
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),
    vehicle_id INTEGER NOT NULL,
    FOREIGN KEY (vehicle_id) REFERENCES vehicle(id) ON DELETE CASCADE
) DEFAULT CHARSET=utf8;

CREATE TABLE part_offer (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    discount DECIMAL(5,2) NOT NULL,
    status ENUM('ACTIVE', 'INACTIVE') DEFAULT 'INACTIVE',
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),
    part_id INTEGER NOT NULL,
    FOREIGN KEY (part_id) REFERENCES part(id) ON DELETE CASCADE
) DEFAULT CHARSET=utf8;
