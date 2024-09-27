Create Table University (
Campus varchar (255),
UniName Varchar (255),
UniAddress varchar (255)
);

Create Table Admin1 (
AdminID int Primary Key Not Null,
AdminName Varchar (255),
Admin_PhoneNum Varchar (255),
AdminEmail Varchar (255)
);

Create Table Class (
BatchNo int Primary Key Not Null,
ClassName Varchar (255),
DepartmentID int,
DepartmentName Varchar (255)
);

Create Table Student (
StudentID int Primary Key Not Null,
StudentName Varchar (255) Not Null,
Class Varchar (100),
CourseID int Foreign Key References Course (CourseID),
CourseName Varchar (255),
DepartmentID int Foreign Key References Department (DepartmentID),
DepartmentName Varchar (255),
Email Varchar (50),
PhoneNumber Varchar(50),
DOB Date,
BloodGrp Varchar (255),
);

Create Table Teacher (
TeacherID int,
TeacherName Varchar (255),
TeacherEmail Varchar (60),
T_Contact Varchar (50),
CourseID int,
CourseName Varchar (80),
DepartmentID int,
DepartmentName Varchar (80),
);


Create Table Course (
CourseID int Primary Key Not Null,
CourseName varchar (200),
CreditHours int
);

Create Table Department (
DepartmentID int Primary Key Not Null,
DepartmentName varchar (200),
);

Insert into University Values
('Islamabad', 'NUML', 'H-9');

Insert into Admin1 Values
(8265, 'Abubakar Bhutta', '0321-1122334', 'abubakar123@gmail.com');

Insert into Class Values
(30, 'BSSE-4B', 100, 'Software Engineering'),
(29, 'BBA-1A', 111, 'BBA'),
(31, 'BSMath-3B', 112, 'SBS Maths');

Insert into Department Values
(100, 'Software Engineering'),
(111, 'BBA'),
(112, 'Maths');

Insert into Course Values
(1, 'Programming Fundamentals', 3),
(2, 'DSA', 3),
(3, 'SRE', 3),
(10, 'Introduction to Business', 3),
(11, 'Accounting Fundamentals', 2),
(12, 'Human Resource Management', 2),
(21, 'Calculus', 2),
(22, 'Linear Algebra', 3),
(23, 'Statistics', 2);

Insert into Student Values
(1, 'Farhan Ali Raza', '4B (Morning)', 3, 'SRE', 100, 'Software Engineering', 'farhan@gmail.com', '0300-5051216', '2001-08-14', 'B+'),
(2, 'Haris Yousaf', '5A (Morning)', 2, 'DSA', 100, 'Software Engineering', 'haris11@gmail.com', '0305-5055123', '2000-01-01', 'AB+'),
(3, 'Ayesha Usman', '1A (Evening)', 10, 'Introduction to Business', 111, 'BBA', 'a_usman21@gmail.com', '0319-1234567', '2002-02-06', 'O+'),
(4, 'Abdullah Tajammal', '2A (Morning)', 21, 'Calculus', 112, 'Maths', 'abdullah@outlook.com', '0344-0071190', '2001-07-21', 'A-'),
(5, 'Maria Ahmed', '8A (Morning)', 12, 'Human Resource Management', 111, 'BBA', 'maria78@live.com', '0333-3111200', '2000-12-25', 'B+');

Insert into Teacher Values
(31, 'Asad Ur Rehman', 'r_asad@gmail.com', '0312-1212123', 11, 'Accounting Fundamentals', 111, 'BBA'),
(39, 'Waris Ali', 'waris79@gmail.com', '0311-5125200', 2, 'DSA', 100, 'Software Engineering'),
(25, 'Sana Rauf', 's_rauf1@gmail.com', '0301-1112910', 21, 'Calculas', 112, 'Maths'),
(64, 'Zohaib Ahmed', 'z.ahmed30@gmail.com', '0310-7654321', 12, 'Human Resource Management', 111, 'BBA'),
(25, 'Sana Rauf', 's_rauf1@gmail.com', '0301-1112910', 22, 'Linear Algebra', 112, 'Maths'),
(62, 'Talal Bin Afzal', 'talal222@yahoo.com', '0333-6979800', 1, 'Programimg Fundamentals', 100, 'Software Engineering'),
(25, 'Sana Rauf', 's_rauf1@gmail.com', '0301-1112910', 23, 'Statistics', 112, 'Maths'),
(50, 'Anam Asghar', 'anam123@outlook.com', '0332-5055786', 3, 'SRE', 100, 'Software Engineering'),
(13, 'Khalid Hussain', 'khalid321@live.com', '0300-0022139', 10, 'Introduction to Business', 111, 'BBA');

Select * From Teacher
Select * From Student
Select * From University
Select * From Admin1
Select * From Class
Select * From Course
Select * From Department


Create Table Course_SE (
CourseID int Not Null,
CourseName varchar (255),
CreditHours int
);

Insert into Course_SE Values
(1, 'Programming Fundamentals', 3),
(2, 'DSA', 3),
(3, 'SRE', 3);

Create Table Course_BBA (
CourseID int Not Null,
CourseName varchar (255),
CreditHours int
);

Insert into Course_BBA Values
(10, 'Introduction to Business', 3),
(11, 'Accounting Fundamentals', 2),
(12, 'Human Resource Management', 2);

Create Table Course_Math (
CourseID int Not Null,
CourseName varchar (255),
CreditHours int
);

Insert into Course_Math Values
(21, 'Calculus', 2),
(22, 'Linear Algebra', 3),
(23, 'Statistics', 2);




-- For Joining all the 4 tables and show the complete record of the students with course and related teachers teaching the courses.
Select
Student.StudentID,
Student.StudentName,
Student.Class,
Student.CourseID,
Course.CourseName AS CourseName,
Course.CreditHours,
Student.DepartmentID,
Department.DepartmentName AS DepartmentName,
Teacher.TeacherID,
Teacher.TeacherName,
Teacher.TeacherEmail,
Teacher.T_Contact

From Student
Join Course ON Student.CourseID = Course.CourseID
JOIN Department ON Student.DepartmentID = Department.DepartmentID
JOIN Teacher ON Student.CourseID = Teacher.CourseID AND Student.DepartmentID = Teacher.DepartmentID
Order by Student.StudentID;

-- For deletion of a Student Record
Delete From Student Where StudentID = 2;

-- For Updating a Specific Column of a Student
Update Student Set BloodGrp = 'AB-' Where StudentID = 2;

-- For Searching the record of a specific Student w.r.t StudentID
Select * From Student Where StudentID = 2;

-- Searching the whole record along with Course and Department Details of a specific Student w.r.t StudentID
Select
Student.StudentID,
Student.StudentName,
Student.Class,
Student.CourseID,
Course.CourseName AS CourseName,
Course.CreditHours,
Student.DepartmentID,
Department.DepartmentName AS DepartmentName,
Student.Email,
Student.PhoneNumber,
Student.DOB,
Student.BloodGrp

From Student
Join Course ON Student.CourseID = Course.CourseID
JOIN Department ON Student.DepartmentID = Department.DepartmentID
Where StudentID = 2;

-- IF you want to add another column in Student Table
Alter Table Student
Add Column Attendance ; --(Now you can use update command to enter the data in the new column)

-- IF you want to enter the whole new record of a system in a student table
Insert into Student (StudentID, StudentName, Class, CourseID, CourseName, DepartmentID, DepartmentName, Email, PhoneNumber, DOB, BloodGrp, Attendance)
Values (6, 'Hassan Ali', '3B (Morning)', 23, 'Statistics', 112, 'Maths', 'hassan_ali@yaahoo.com', '0314-5700123', '2003-05-20', 'O-', '88%');

-- If you want to change the data type of a coulumn
Alter Table Student
Alter Column Attendance Varchar (255);

