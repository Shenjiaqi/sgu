#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;
ll Base = 1e9;

int gProblemNum;
string gMyTeamName;
char gPline[100007];
size_t gLineCount;

void SkipSpace(int& i)
{
  for (; i < gLineCount && gPline[i] == ' '; ++i)
    ;
}

bool GetLine()
{
  
  if (gLineCount <= 0)
    {
      gLineCount = 0;
      for (char tmp;;)
	{
	  tmp = getchar();
	  if (tmp == EOF)
	    {
	      gPline[gLineCount] = 0;
	      return false;
	    }
	  gPline[gLineCount] = tmp;
	  if (tmp == '\n')
	    {
	      gPline[gLineCount] = 0;
	      break;
	    }
	  ++gLineCount;
	}
      if (gLineCount == 0)
	{
	  return false;
	}
      for (int i = 0; i < gLineCount; ++i)
	{
	  if (gPline[i] != ' ' && gPline[i] != '\n')
	    {
	      return true;
	    }
	}
      return false;
    }

  return true;
}

class BigNum
{
public:
  vector<int> mVal;
  bool operator <(const BigNum& rho) const
  {
    if (mVal.size() != rho.mVal.size())
      {
	return mVal.size() < rho.mVal.size();
      }

    for (int i(mVal.size() - 1); i >= 0; --i)
      {
	if (mVal[i] != rho.mVal[i])
	  {
	    return mVal[i] < rho.mVal[i];
	  }
      }

    return false;
  }

  const BigNum operator*(int val)
  {
    BigNum rtn;

    if (val == 0)
      {
	return rtn;
      }

    ll carry(0);
    for (int i = 0; i < mVal.size(); ++i)
      {
	carry += (ll)val * mVal[i];

	rtn.mVal.push_back(carry % Base);
	carry /= Base;
      }

    if (carry > 0)
      {
	rtn.mVal.push_back(carry);
      }

    return rtn;
  }

  const BigNum& operator+=(int val)
  {
    ll carry(val);

    for (int i = 0; carry > 0; ++i)
      {
	if (mVal.size() <= i)
	  {
	    mVal.push_back(0);
	  }

	carry += mVal[i];

	mVal[i] = carry % Base;
	carry /= Base;
      }

    return *this;
  }

  const BigNum& operator +=(const BigNum& rho)
  {
    ll carry(0);
    int i(0);
    for (; i < rho.mVal.size(); ++i)
      {
	if (i >= mVal.size())
	  {
	    mVal.push_back(0);
	  }

	carry += (ll)mVal[i] + rho.mVal[i];

	mVal[i] = carry % Base;
	carry /= Base;
      }

    for (; carry > 0; ++i)
      {
	if (i >= mVal.size())
	  {
	    mVal.push_back(0);
	  }

	carry += mVal[i];
	mVal[i] = carry % Base;
	carry /= Base;
      }

    return *this;
  }

  void Read(const char* s, int f, int t)
  {
    mVal.clear();
    for (; t > f; t-= 9)
      {
	int val(0);
	for (int i = max(f, t - 9); i < t; ++i)
	  {
	    val = val * 10 + (int)(s[i] - '0');
	  }

	mVal.push_back(val);
      }
  }

  void prt() const
  {
    int size = mVal.size();

    if (size == 0)
      {
	printf("0");
      }
    else
      {
	printf("%d", mVal[size - 1]);
	for (int i = size - 2; i >= 0; --i)
	  {
	    printf("%09d", mVal[i]);
	  }
      }

    printf("\n");
  }
};

class Team
{
public:
  string mName;
  int mAc;
  vector<BigNum> mPenalty4Reject;
  BigNum mPenalty;
  int mRank;
  void swap(Team& rho)
  {
    using std::swap;
    mName.swap(rho.mName);
    swap(mAc, rho.mAc);
    mPenalty4Reject.swap(rho.mPenalty4Reject);
    mPenalty.mVal.swap(rho.mPenalty.mVal);
    swap(mRank, rho.mRank);
  }

  bool Read();

  void SubmitAnsACIn(int time)
  {
    ++mAc;
    mPenalty += mPenalty4Reject[mPenalty4Reject.size() - 1] * 20;
    mPenalty += time;
    mPenalty4Reject.pop_back();
  }

  void prt() const
  {
    cout << "mName: " << mName << endl;
    cout << "mAc: " << mAc << endl;
    cout << "mPenalty4Reject size: " << mPenalty4Reject.size() << endl;
    for (int i = 0; i < mPenalty4Reject.size(); ++i)
      {
	mPenalty4Reject[i].prt();
      }
    cout << "mPenalty: " << endl;
    mPenalty.prt();
    cout << "mRank: " << mRank << endl;
  }

};

bool IsTeamInfo()
{
  for (int i = 0; i < gLineCount; ++i)
    {
      const char& c = gPline[i];
      if (c == '.' || c == '+' || c == '-')
	{
	  return true;
	}
    }

  return false;
}

bool Team::Read()
{
  GetLine();
  if (!IsTeamInfo())
    {
      return false;
    }

  mPenalty4Reject.clear();

  for (int problemLeft(gProblemNum); problemLeft > 0; --problemLeft)
    {
      --gLineCount;
      // skip space
      for (; gPline[gLineCount] == ' '; --gLineCount)
	;

      int to(gLineCount + 1);
      for (char *c = gPline + gLineCount; *c <= '9' && *c >= '0';
	   --c, --gLineCount)
	;

      BigNum num;
      num.Read(gPline, gLineCount + 1, to);

      for (;gLineCount > 0 && gPline[gLineCount] == ' '; --gLineCount)
	;

      if (gPline[gLineCount] == '+')
	{
	  ++mAc;
	}
      else // '.' or '-'
	{
	  mPenalty4Reject.push_back(num);
	}
    }
  
  {
    // get penalty
    --gLineCount;
    for (; gPline[gLineCount] == ' '; --gLineCount)
      ;

    int to(gLineCount + 1);
    for (; gPline[gLineCount] <= '9' && gPline[gLineCount] >= '0';
	 --gLineCount)
      ;

    mPenalty.mVal.clear();
    mPenalty.Read(gPline, gLineCount + 1, to);
  }
  
  {
    // get how many problems solved
    for (; gPline[gLineCount] == ' '; --gLineCount)
      ;

    mAc = 0;
    for (int base(1); gPline[gLineCount] <= '9' && gPline[gLineCount] >= '0';
	 base *= 10, --gLineCount)
      {
	mAc += base * (int)(gPline[gLineCount] - '0');
      }
  }

  {
    // get rank
    int s(0);
    for (; gPline[s] == ' '; ++s)
      ;
    mRank = 0;
    for (; gPline[s] <= '9' && gPline[s] >= '0'; ++s)
      {
	mRank = mRank * 10 + (gPline[s] - '0');
      }

    // get name of team
    for (; gPline[s] == ' '; ++s)
      ;
    for (; gPline[gLineCount] == ' '; --gLineCount)
      ;

    mName.assign(gPline + s, gPline + gLineCount + 1);
  }

  gLineCount = 0;

  // prt();

  return true;
}

bool BetterThan(const Team& team1, const Team& team2)
{
  if (team1.mAc != team2.mAc)
    {
      return team1.mAc > team2.mAc;
    }

  return team1.mPenalty < team2.mPenalty;
}

int GetHighPos(vector<Team> teams, int myTeamIdx, int submitLeft)
{
  Team& myTeam(teams[myTeamIdx]);

  for (; submitLeft > 0 && myTeam.mAc < gProblemNum;)
    {
      myTeam.SubmitAnsACIn(241);

      --submitLeft;
    }

  int teamCount(teams.size());

  if ( (myTeamIdx != teamCount - 1) ||
       (myTeamIdx == teamCount - 1 && 
	(myTeamIdx == 0 || (myTeamIdx > 0 && 
			    teams[myTeamIdx - 1].mAc < gProblemNum))))
    {
      submitLeft = 0;
    }

  if (submitLeft > 0)
    {
      myTeam.mPenalty += (submitLeft * 20);
    }

  // myTeam.prt();
  // teams[0].prt();

  int rank(myTeamIdx + 1);
  for (int i(myTeamIdx - 1); i >= 0 && !BetterThan(teams[i], myTeam); --i)
    {
      --rank;
    }

  return rank;
}

int GetLowPos(vector<Team> teams, int myTeamIdx, int submitLeft)
{
  int teamCount(teams.size());

  for (int i = myTeamIdx - 1; i >= 0 && teams[i].mRank == teams[myTeamIdx].mRank; --i)
    {
      if (i == 0 || teams[i - 1].mRank != teams[myTeamIdx].mRank)
	{
	  swap(teams[i], teams[myTeamIdx]);
	  myTeamIdx = i;
	  break;
	}
    }

  Team& myTeam(teams[myTeamIdx]);

  int rank(myTeam.mRank);
  for (int i(myTeamIdx + 1); submitLeft > 0 && i < teamCount;)
    {
      int j(i);
      for (; i < teamCount && teams[i].mAc == teams[j].mAc; ++i)
	;

      int det = myTeam.mAc - teams[j].mAc;


      if (submitLeft < det)
	{
	  break;
	}

      for (int l = j; l < i; ++l)
	{
	  for (int k = 0; k < det; ++k)
	    {
	      teams[l].SubmitAnsACIn(241);
	    }
	}

      for (int l = j; submitLeft >= det && l < i; ++l)
	{
	  if (BetterThan(teams[l], myTeam))
	    {
	      submitLeft -= det;
	      ++rank;
	    }
	}

      for (int l = j; submitLeft >= 1 + det && l < i; ++l)
	{
	  if (!BetterThan(teams[l], myTeam) && teams[l].mAc < gProblemNum)
	    {
	      submitLeft -= (det + 1);
	      teams[l].SubmitAnsACIn(241);
	      ++rank;
	    }
	}
    }

  return rank;
}

bool GetProblemInfo()
{
  if (!GetLine())
    {
      return false;
    }

  int i(0);
  SkipSpace(i);
  i += strlen("Rank");
  SkipSpace(i);
  i += strlen("Team");
  SkipSpace(i);
  i += strlen("=");
  SkipSpace(i);
  i += strlen("Penalty");

  gProblemNum = 0;

  for (; i < gLineCount; ++i)
    {
      SkipSpace(i);
      if (i < gLineCount && gPline[i] <= 'Z' && gPline[i] >= 'A')
	{
	  ++gProblemNum;
	}
    }

  gLineCount = 0;

  return true;
}

int main()
{
  for (;;)
    {
      // get how many problems
      if (!GetProblemInfo())
	{
	  break;
	}

      // extract team info
      vector<Team> teams;
      for (;;)
	{
	  Team team;
	  if (!team.Read())
	    {
	      break;
	    }
	  sort(team.mPenalty4Reject.begin(), team.mPenalty4Reject.end());
	  reverse(team.mPenalty4Reject.begin(), team.mPenalty4Reject.end());
	  teams.push_back(team);
	}

      // how many submits in the last hour
      GetLine();
      int lastHourSubmit(0);
      sscanf(gPline, "%d", &lastHourSubmit);
      gLineCount = 0;

      // get my team name
      GetLine();
      {
	int i = 0;
	for (; gPline[i] == ' ' && i < gLineCount; ++i)
	  ;
	for (--gLineCount; gLineCount != 0 && gPline[gLineCount] == ' '; --gLineCount)
	  {
	    gPline[gLineCount] = 0;
	  }
	gMyTeamName = gPline + i;
      }
      gLineCount = 0;

      // get my team index in teams
      int myTeamIdx(0);
      for (vector<Team>::const_iterator ite(teams.begin())
	     ; ite != teams.end(); ++ite)
	{
	  if (ite->mName == gMyTeamName)
	    {
	      break;
	    }

	  ++myTeamIdx;
	}
      // calculate answer
      int highPos = GetHighPos(teams, myTeamIdx, lastHourSubmit);
      int lowPos = GetLowPos(teams, myTeamIdx, lastHourSubmit);

      // print answer
      printf("%d %d\n", highPos, lowPos);
    }
  return 0;
}
