
Functional Dependencies:

Event :

Event_Id -> { Event_Name, Discription, EDate , Duration }

The table is in BCNF and hence, in 3NF since all the non-key attributes are fully dependent
on the primary key and the only functional dependencies are the ones between the primary
key and the non-key attributes. Hence all determinants are candidate keys, thus satisfying
the condition for BCNF.

Users :

User_Id -> { First_Name,Last_Name, UGorPG, Branch,DOB, Hostel }

The table is in BCNF and hence, in 3NF for the same reason as above.

User_Contact :

User_Id -> { Contact_No,Email }

The table is in BCNF and hence, in 3NF for the same reason as above.
User_Contact is a multivalued attribute to Users table and therefore User_Id will be the 
primary key to User_Contact table.

Organizer : 

Org_Id -> {  Org_Name, Org_Type ,Faculty_Advisor  }

The table is in BCNF and hence, in 3NF for the same reason as above


Org_Contact :

Org_Id -> { Contact_No, Email  }

The table is in BCNF and hence, in 3NF for the same reason as above.
Org_Contact is a multivalued attribute to Organizer table and therefore Org_Id will be the 
primary key to Org_Contact table.


Venue :

Primary key = { Building, Room_No }

No functional dependencies exist as there are no other attributes.
The table is in BCNF and hence, in 3NF for the same reason as above.



Conducted_by:

Primary key = { Event_Id, Org_Id }

No functional dependencies exist as there are no other attributes.
The table is in BCNF and hence, in 3NF for the same reason as above.



Event_Summary:

{ Event_Id, Org_Id } -> { Expenses, Rating }

The table is in BCNF and hence, in 3NF for the same reason as above.



Event_Survey:

{ Event_Id, User_Id } -> { Intrested , Feedback }

The table is in BCNF and hence, in 3NF for the same reason as above.



Team:

Team_Id -> {  Team_Name , Leader_UId  }

The table is in BCNF and hence, in 3NF for the same reason as above.



Team_Contact:

Team_Id -> {  Contact_No, Email }

The table is in BCNF and hence, in 3NF for the same reason as above.
Team_Contact is a multivalued attribute to Team table and therefore Team_Id will be the 
primary key to Team_Contact table.



Consist_Of:

Primary key = { Event_Id, User_Id }

No functional dependencies exist as there are no other attributes.
The table is in BCNF and hence, in 3NF for the same reason as above.



Winner_Teams:

{ Team_Id, Event_Id } -> { Position_Held ,Prize }

The table is in BCNF and hence, in 3NF for the same reason as above.



Participated_Teams:

Primary key = { Event_Id, Team_Id }

No functional dependencies exist as there are no other attributes.
The table is in BCNF and hence, in 3NF for the same reason as above.