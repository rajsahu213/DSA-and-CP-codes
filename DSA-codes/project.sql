

create table Event (Event_Id int primary key, Event_Name varchar(50) not null, Discription varchar(100),
EDate date, Duration int);


create table Users (User_Id int primary key , First_Name varchar(20), Last_Name varchar(20), UGorPG
varchar(5), Branch varchar(20), DOB date, Hostel varchar(20));


create table User_Contact(Contact_No int, Email varchar(50), User_Id int primary key, foreign key (User_Id)
references Users(User_Id));


create table Organizer(Org_Id int primary key, Head_UId int, Org_Name varchar(50), Org_Type
varchar(50), Faculty_Advisor varchar(50), foreign key (Head_UId) references Users(User_Id));

create table Org_Contact(Contact_No int, Email varchar(50), Org_Id int primary key, foreign key (Org_Id) references
Organizer(Org_Id));

create table Venue(Event_Id int, Building varchar(20), Room_No varchar(5), foreign key (Event_Id)
references Event(Event_Id));

create table Conducted_by(Event_Id int, Org_Id int,
foreign key (Org_Id) references Organizer(Org_Id),
foreign key (Event_Id) references Event(Event_Id),
primary key(Event_Id,Org_Id)
);

create table Event_Summary(Event_Id int, Org_Id int, Summary varchar(100), Expenses int, Rating int,
foreign key (Org_Id) references Organizer(Org_Id),
foreign key (Event_Id) references Event(Event_Id),
primary key(Event_Id,Org_Id)
);

create table Event_Survey(Event_Id int, User_Id int, Intrested varchar(5), Feedback varchar(50),
foreign key (User_Id) references Users(User_Id),
foreign key (Event_Id) references Event(Event_Id),
primary key(Event_Id,User_Id)
);

create table Team(Team_Id int primary key, Team_Name varchar(20), Leader_UId int,
foreign key (Leader_UId) references Users(User_Id));

create table Team_Contact(Contact_No int, Email varchar(50), Team_Id int, foreign key (Team_Id)
references Team(Team_Id));

create table Consist_Of(Team_Id int , User_Id int,
foreign key (User_Id) references Users(User_Id),
foreign key (Team_Id) references Team(Team_Id)
primary key (Team_Id,User_Id)
);

create table Winner_Teams(Position_Held int, Prize varchar(50), Team_Id int, Event_Id int,
foreign key (Event_Id) references Event(Event_Id),
foreign key (Team_Id) references Team(Team_Id));

create table Participated_Teams(Team_Id int, Event_Id int,
foreign key (Event_Id) references Event(Event_Id),
foreign key (Team_Id) references Team(Team_Id)
primary key(Team_Id,Event_Id)
);