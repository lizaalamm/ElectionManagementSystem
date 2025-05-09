/******************************************************************************
* ELECTION MANAGEMENT SYSTEM *
******************************************************************************/
#include &lt;iostream&gt;
#include &lt;fstream&gt;
#include &lt;string&gt;
#include &lt;vector&gt; /*Vectors are commonly used when the number of elements is unknown or might
change during program execution.*/
#include &lt;map&gt; /* commonly used to implement associative arrays or dictionaries.*/

using namespace std;

// Base class for a Candidate

May 26,
2024 OOP FINAL PROECT REPORT
class Candidate {
public:
int CandidateId;
string CandidateName;
string Gender;
int Age;
int PartyId;

// Constructor to initialize a Candidate
Candidate(int id, string name, string gender, int age, int partyId)
: CandidateId(id), CandidateName(name), Gender(gender), Age(age), PartyId(partyId) {}

// Virtual function to display candidate details
virtual void CandidateDetails() const {
cout &lt;&lt; &quot;Candidate: &quot; &lt;&lt; CandidateName &lt;&lt; &quot;, ID: &quot; &lt;&lt; CandidateId &lt;&lt; &quot;, Gender: &quot; &lt;&lt; Gender &lt;&lt; &quot;,
Age: &quot; &lt;&lt; Age &lt;&lt; &quot;, PartyID: &quot; &lt;&lt; PartyId &lt;&lt; endl;
}

// Virtual function for voting
virtual void Vote() const {
cout &lt;&lt; CandidateName &lt;&lt; &quot; votes...&quot; &lt;&lt; endl;
}
};

// Derived class for a Local Candidate
class LocalCandidate : public Candidate {

May 26,
2024 OOP FINAL PROECT REPORT
public:
string Constituency;

// Constructor to initialize a Local Candidate
LocalCandidate(int id, string name, string gender, int age, int partyId, string constituency)
: Candidate(id, name, gender, age, partyId), Constituency(constituency) {}

// Override function to display local candidate details
void CandidateDetails() const override {
Candidate::CandidateDetails();
cout &lt;&lt; &quot;Constituency: &quot; &lt;&lt; Constituency &lt;&lt; endl;
}

// Override function for voting in a local constituency
void Vote() const override {
cout &lt;&lt; CandidateName &lt;&lt; &quot; casts vote in constituency &quot; &lt;&lt; Constituency &lt;&lt; &quot;...&quot; &lt;&lt; endl;
}
};

// Derived class for a National Candidate
class NationalCandidate : public Candidate {
public:
string Position;

// Constructor to initialize a National Candidate

May 26,
2024 OOP FINAL PROECT REPORT
NationalCandidate(int id, string name, string gender, int age, int partyId, string position)
: Candidate(id, name, gender, age, partyId), Position(position) {}

// Override function to display national candidate details
void CandidateDetails() const override {
Candidate::CandidateDetails();
cout &lt;&lt; &quot;Position: &quot; &lt;&lt; Position &lt;&lt; endl;
}

// Override function for voting in a national election
void Vote() const override {
cout &lt;&lt; CandidateName &lt;&lt; &quot; casts national vote for &quot; &lt;&lt; Position &lt;&lt; &quot; position...&quot; &lt;&lt; endl;
}
};

// Class for a Party
class Party {
public:
int PartyId;
string PartyName;
string LeaderName;
int TotalCandidates;

// Constructor to initialize a Party
Party(int id, string name, string leader, int candidates)

May 26,
2024 OOP FINAL PROECT REPORT
: PartyId(id), PartyName(name), LeaderName(leader), TotalCandidates(candidates) {}

// Function to display party details
void PartyDetails() const {
cout &lt;&lt; &quot;Party: &quot; &lt;&lt; PartyName &lt;&lt; &quot;, Leader: &quot; &lt;&lt; LeaderName &lt;&lt; &quot;, Candidates: &quot; &lt;&lt;
TotalCandidates &lt;&lt; endl;
}
};

// Class for a Polling Station
class PollingStation {
public:
int StationId;
string Location;
int TotalVoters;

// Constructor to initialize a Polling Station
PollingStation(int id, string location, int voters) : StationId(id), Location(location), TotalVoters(voters)
{}

// Function to display polling station details
void PollingStationDetails() const {
cout &lt;&lt; &quot;Polling Station: &quot; &lt;&lt; StationId &lt;&lt; &quot;, Location: &quot; &lt;&lt; Location &lt;&lt; &quot;, Voters: &quot; &lt;&lt; TotalVoters &lt;&lt;
endl;
}
};

May 26,
2024 OOP FINAL PROECT REPORT

// Class for a Voter
class Voter {
public:
int VoterId;
string Name;
int Age;
string Gender;
string Constituency;
bool HasVoted;

// Constructor to initialize a Voter
Voter(int id, string name, int age, string gender, string constituency)
: VoterId(id), Name(name), Age(age), Gender(gender), Constituency(constituency), HasVoted(false)
{}

// Function to display voter details
void VoterDetails() const {
cout &lt;&lt; &quot;Voter ID: &quot; &lt;&lt; VoterId &lt;&lt; &quot;, Name: &quot; &lt;&lt; Name &lt;&lt; &quot;, Age: &quot; &lt;&lt; Age &lt;&lt; &quot;, Gender: &quot; &lt;&lt; Gender
&lt;&lt; &quot;, Constituency: &quot; &lt;&lt; Constituency &lt;&lt; endl;
}

// Function to cast a vote
void Vote() {
if (HasVoted) {
cout &lt;&lt; &quot;You have already voted.&quot; &lt;&lt; endl;

May 26,
2024 OOP FINAL PROECT REPORT
} else {
cout &lt;&lt; &quot;You cast your vote.&quot; &lt;&lt; endl;
HasVoted = true;
}
}
};

// Class to store and manage election results
class ElectionResult {
public:
map&lt;int, int&gt; candidateVotes; // Maps candidate ID to the number of votes received

// Function to add a vote for a candidate
void AddVote(int candidateId) {
candidateVotes[candidateId]++;
}

// Function to get the total votes for a candidate
int GetTotalVotes(int candidateId) const {
if (candidateVotes.find(candidateId) != candidateVotes.end()) {
return candidateVotes.at(candidateId);
}
return 0; // If candidate ID not found, return 0 votes
}
};

May 26,
2024 OOP FINAL PROECT REPORT

// Main class to manage the election process
class ElectionManagement {
public:
string ElectionName;
string Date;
string Location;
vector&lt;Party&gt; parties;
vector&lt;PollingStation&gt; pollingStations;
vector&lt;Candidate*&gt; candidates;
vector&lt;Voter&gt; voters;
ElectionResult electionResult; // Instance of ElectionResult class

// Constructor to initialize the Election Management system
ElectionManagement(string name, string date, string location)
: ElectionName(name), Date(date), Location(location) {}

// Function to check if the election is open (placeholder)
bool IsOpen() const {
return true; // Election Status Check
}

// Function to display election details
void ElectionDetails() const {
cout &lt;&lt; &quot;Election: &quot; &lt;&lt; ElectionName &lt;&lt; &quot;, Date: &quot; &lt;&lt; Date &lt;&lt; &quot;, Location: &quot; &lt;&lt; Location &lt;&lt; endl;

May 26,
2024 OOP FINAL PROECT REPORT
}

// Function to add a candidate to the list
//Adding Candidates and Voters
void AddCandidate(Candidate* candidate) {
candidates.push_back(candidate); //The push_back method is essential for dynamically growing
the candidates vector
}

// Function to add a voter to the list
void AddVoter(const Voter&amp; voter) {
voters.push_back(voter);
}

// Function to display all candidates
void DisplayCandidates() const {
cout &lt;&lt; &quot;========== Candidates ==========&quot; &lt;&lt; endl;
for (int i = 0; i &lt; candidates.size(); ++i) {
candidates[i]-&gt;CandidateDetails();
}
cout &lt;&lt; &quot;===============================&quot; &lt;&lt; endl;
}

// Function to conduct the election
void ConductElection() {
cout &lt;&lt; &quot;Conducting election...&quot; &lt;&lt; endl;

May 26,
2024 OOP FINAL PROECT REPORT
cout &lt;&lt; &quot;Candidates:&quot; &lt;&lt; endl;

map&lt;int, int&gt; idMap; // Map to store displayed ID to actual candidate ID

// Display candidates with unique IDs for voting
for (size_t i = 0; i &lt; candidates.size(); ++i) {
int displayId = i + 1;
idMap[displayId] = candidates[i]-&gt;CandidateId;
cout &lt;&lt; &quot;ID: &quot; &lt;&lt; displayId &lt;&lt; endl;
candidates[i]-&gt;CandidateDetails();
cout &lt;&lt; endl;
}

int choice;
cout &lt;&lt; &quot;Enter the ID of the candidate you want to vote for: &quot;;
cin &gt;&gt; choice;
cin.ignore();

// Validate the choice against the display IDs
if (idMap.find(choice) == idMap.end()) {
cout &lt;&lt; &quot;Invalid candidate ID. Please try again.&quot; &lt;&lt; endl;
return;
}

int actualCandidateId = idMap[choice];

May 26,
2024 OOP FINAL PROECT REPORT
for (const auto&amp; candidate : candidates) {
if (candidate-&gt;CandidateId == actualCandidateId) {
cout &lt;&lt; &quot;You voted for: &quot; &lt;&lt; endl;
candidate-&gt;Vote();
// Add vote to election result
electionResult.AddVote(actualCandidateId);
cout &lt;&lt; &quot;Election completed!&quot; &lt;&lt; endl;
return;
}
}
}

// Function to display the election results
void DisplayElectionResult() const {
cout &lt;&lt; &quot;========== Election Result ==========&quot; &lt;&lt; endl;
for (const auto&amp; pair : electionResult.candidateVotes) {
cout &lt;&lt; &quot;Candidate ID: &quot; &lt;&lt; pair.first &lt;&lt; &quot;, Votes: &quot; &lt;&lt; pair.second &lt;&lt; endl;
}
cout &lt;&lt; &quot;=====================================&quot; &lt;&lt; endl;
}
};

// Function to display the main menu
void displayMenu() {
cout &lt;&lt; &quot;\t\t\t\t\t\tElection Management System Menu &quot; &lt;&lt; endl;

May 26,
2024 OOP FINAL PROECT REPORT
cout &lt;&lt; &quot;1. Add Party&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;2. Add Polling Station&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;3. Add Candidate&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;4. Add Voter&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;5. Display Candidates&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;6. Conduct Election&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;7. View Election Result&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;8. Exit&quot; &lt;&lt; endl;
cout &lt;&lt; endl &lt;&lt; endl &lt;&lt; endl &lt;&lt; endl;
cout &lt;&lt; &quot;Enter your choice: &quot;;
}

// Function to add candidate information to a file
void addCandidateToFile(const Candidate&amp; candidate) {
ofstream file(&quot;candidates.txt&quot;, ios::app); //APPEND MODE
if (file.is_open()) {
file &lt;&lt; &quot;Candidate: &quot; &lt;&lt; candidate.CandidateName &lt;&lt; &quot;, ID: &quot; &lt;&lt; candidate.CandidateId &lt;&lt; &quot;, Gender:
&quot; &lt;&lt; candidate.Gender &lt;&lt; &quot;, Age: &quot; &lt;&lt; candidate.Age &lt;&lt; &quot;, PartyID: &quot; &lt;&lt; candidate.PartyId &lt;&lt; endl;
file.close();
} else {
cout &lt;&lt; &quot;Unable to open file&quot;;
}
}

// Main function
int main() {

May 26,
2024 OOP FINAL PROECT REPORT
cout &lt;&lt;
&quot;******************************************************************************&quot; &lt;&lt;
endl;
cout &lt;&lt; &quot;* ELECTION MANAGEMENT SYSTEM *&quot; &lt;&lt; endl;
cout &lt;&lt;
&quot;******************************************************************************&quot; &lt;&lt;
endl;
// Create an instance of the Election Management system
ElectionManagement em(&quot;General Election&quot;, &quot;2024-11-04&quot;, &quot;City Hall&quot;);

while (true) {
displayMenu();
int choice;
cin &gt;&gt; choice;
cin.ignore(); // Clear the newline character from the input buffer

if (choice == 1) {
int partyId;
string partyName, leaderName;
int totalCandidates;
cout &lt;&lt; &quot;Enter Party ID: &quot;;
cin &gt;&gt; partyId;
cin.ignore();
cout &lt;&lt; &quot;Enter Party Name: &quot;;
getline(cin, partyName);
cout &lt;&lt; &quot;Enter Leader Name: &quot;;
getline(cin, leaderName);

May 26,
2024 OOP FINAL PROECT REPORT
cout &lt;&lt; &quot;Enter Total Candidates: &quot;;
cin &gt;&gt; totalCandidates;
cin.ignore();

Party party(partyId, partyName, leaderName, totalCandidates);
em.parties.push_back(party);
cout &lt;&lt; &quot;Party added successfully.&quot; &lt;&lt; endl; // Success message
} else if (choice == 2) {
int stationId;
string location;
int totalVoters;
cout &lt;&lt; &quot;Enter Polling Station ID: &quot;;
cin &gt;&gt; stationId;
cin.ignore();
cout &lt;&lt; &quot;Enter Location: &quot;;
getline(cin, location);
cout &lt;&lt; &quot;Enter Total Voters: &quot;;
cin &gt;&gt; totalVoters;
cin.ignore();

PollingStation station(stationId, location, totalVoters);
em.pollingStations.push_back(station);
cout &lt;&lt; &quot;Polling station added successfully.&quot; &lt;&lt; endl; // Success message
} else if (choice == 3) {
int candidateId;

May 26,
2024 OOP FINAL PROECT REPORT
string candidateName, gender, constituency, position;
int age, partyId;
cout &lt;&lt; &quot;Enter Candidate ID: &quot;;
cin &gt;&gt; candidateId;
cin.ignore();
cout &lt;&lt; &quot;Enter Candidate Name: &quot;;
getline(cin, candidateName);
cout &lt;&lt; &quot;Enter Gender: &quot;;
getline(cin, gender);
cout &lt;&lt; &quot;Enter Age: &quot;;
cin &gt;&gt; age;
cin.ignore();
cout &lt;&lt; &quot;Enter Party ID: &quot;;
cin &gt;&gt; partyId;
cin.ignore();
cout &lt;&lt; &quot;Is this a local or national candidate? (Enter &#39;local&#39; or &#39;national&#39;): &quot;;
string type;
getline(cin, type);

Candidate* candidate;
if (type == &quot;local&quot;) {
cout &lt;&lt; &quot;Enter Constituency: &quot;;
getline(cin, constituency);
candidate = new LocalCandidate(candidateId, candidateName, gender, age, partyId,
constituency);
} else if (type == &quot;national&quot;) {

May 26,
2024 OOP FINAL PROECT REPORT
cout &lt;&lt; &quot;Enter Position: &quot;;
getline(cin, position);
candidate = new NationalCandidate(candidateId, candidateName, gender, age, partyId,
position);
} else {
cout &lt;&lt; &quot;Invalid candidate type. Please try again.&quot; &lt;&lt; endl;
continue;
}

em.AddCandidate(candidate);
addCandidateToFile(*candidate); // Add candidate to file
cout &lt;&lt; &quot;Candidate added successfully.&quot; &lt;&lt; endl; // Success message
} else if (choice == 4) {
int voterId;
string name, gender, constituency;
int age;
cout &lt;&lt; &quot;Enter Voter ID: &quot;;
cin &gt;&gt; voterId;
cin.ignore();
cout &lt;&lt; &quot;Enter Name: &quot;;
getline(cin, name);
cout &lt;&lt; &quot;Enter Age: &quot;;
cin &gt;&gt; age;
cin.ignore();
cout &lt;&lt; &quot;Enter Gender: &quot;;
getline(cin, gender);

May 26,
2024 OOP FINAL PROECT REPORT
cout &lt;&lt; &quot;Enter Constituency: &quot;;
getline(cin, constituency);

Voter voter(voterId, name, age, gender, constituency);
em.AddVoter(voter);
cout &lt;&lt; &quot;Voter added successfully.&quot; &lt;&lt; endl; // Success message
} else if (choice == 5) {
em.DisplayCandidates();
} else if (choice == 6) {
em.ConductElection();
} else if (choice == 7) {
em.DisplayElectionResult();
} else if (choice == 8) {
cout &lt;&lt; &quot;Exiting Election Management System...&quot; &lt;&lt; endl;
break;
} else {
cout &lt;&lt; &quot;Invalid choice. Please try again.&quot; &lt;&lt; endl;
}
}

return 0;
}
