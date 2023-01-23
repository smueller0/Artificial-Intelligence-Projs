// TEAM MEMBERS:
// Jordan Finney, Mason Greenwell, Sarah Mueller
#include <iostream>

 // 1. Bipolar Disorder - feeling sad or hopeless. lacking energy. difficulty concentrating. loss of interest in everyday activities. feelings of emptiness or worthlessness. feelings of guilt and despair. feeling pessimistic about everything. self-doubt.

 // 2. Schizophrenia - delusions, hallucinations, disorganized speech, trouble with thinking and lack of motivation.

 // 3. Schizo-affective Disorder - Delusions. having false, fixed beliefs, despite evidence to the contrary.Hallucinations, such as hearing voices or seeing things that aren't there.Impaired communication and speech, such as being incoherent.Bizarre or unusual behavior.Symptoms of depression, such as feeling empty, sad or worthless.
 
 // 4. Major Depressive Disorder - changes in sleep, appetite, energy level, concentration, daily behavior, or self-esteem. Feelings of sadness, tearfulness, emptiness or hopelessness. Angry outbursts, irritability or frustration, even over small matters.

 // 5. Panic Disorder with Agoraphobia - Symptoms include fear and avoidance of places and situations that might cause feelings of panic, entrapment, helplessness, or embarrassment. The anxiety is caused by fear that there's no easy way to escape or get help if the anxiety intensifies. Most people who have agoraphobia develop it after having one or more panic attacks, causing them to worry about having another attack and avoid the places where it may happen again.

 // 6. Dissociative Identity Disorder - is usually a reaction to trauma as a way to help a person avoid bad memories. Dissociative identity disorder is characterized by the presence of two or more distinct personality identities. Each may have a unique name, personal history, and characteristics.

 // 7. Dysthymia - defined as a low mood occurring for at least two years, along with at least two other symptoms of depression. Examples of symptoms include lost interest in normal activities, hopelessness, low self-esteem, low appetite, low energy, sleep changes, and poor concentration.

 // 8. Generalized Anxiety Disorder - The condition has symptoms similar to panic disorder, obsessive-compulsive disorder, and other types of anxiety. These symptoms include constant worry, restlessness, and trouble with concentration.

using namespace std;

int bwd_chain();
void fwd_chain(int);

int main(){
  int rule_num = 0;
  int clause_num = 0;
  string treatment;
  string disorder;
  
  cout << "Hello patient, welcome to the Mental Health Assesment..." << endl;

  cout <<  "As you are going through the following questions please type 'Y' for yes and 'N' for no. Thank you." << endl << endl;

  cout << "Starting part one, running evlauation ..." << endl;
  
  // the value of the position is your disorder type
  rule_num = bwd_chain();
  
  clause_num = 4 * (rule_num / 10 - 1)+ 1;
  cout << endl;
  cout << "This is your clause number " << clause_num << ", this is your rule number " << rule_num << "." << endl;
  cout << endl;

  cout << "You have completed the end of part one, for part two we will calulate the best treatment that fits you..." << endl;
  cout << endl;
  // the rule num of the disorder
  fwd_chain(clause_num);

  cout << endl;

  cout << "WARNING: We are not mental health experts, we are computer scientist. Although we trust our system to give you accurate results, we reccomend you consult wilth your personal doctor. " << endl;  cout << "Thank you for using the Mental Health Assesment..." << endl;
  return 0;
}
// backward chaining function
// find the value of the position (mental illness)
// FORMULA
//  clause_num = 4 * (rule_num / 10 - 1)+ 1;
int bwd_chain()
{
  // backward chaining find the value of the position 
  char choice;
  int val_of_pos = 0; // integer position = equals disorder 
   // establish char as yes or no answer choices 

  int rule_num; // rule number 
  int clause_num; // clause number 

  cout << "Are you experiencing emotional problems?" << endl;
  cin >> choice;
  if(choice == 'Y')
  {
    rule_num = 20;
    clause_num = 4 * (rule_num / 10 - 1)+ 1;
    cout<< "Have you been sad for 2 plus weeks?" << endl; 
    cin >> choice;
    if(choice == 'N')
    {
      rule_num = 30;
      clause_num = 4 * (rule_num / 10 - 1)+ 1;
      cout << "Do you hallucinate?" << endl;
      cin >> choice;
      if(choice == 'Y')
      {
        rule_num = 40;
        clause_num = 4 * (rule_num / 10 - 1)+ 1;
        //Schizophrenia
        return rule_num;
      }
      else
      {
        cout << "Have you experienced trauma?" <<endl;
        cin >> choice;
        if(choice == 'Y')
        {
          rule_num = 50;
          clause_num = 4 * (rule_num / 10 - 1)+ 1;
          //Dissociative Identity Disorder 
          return rule_num;
        }
        else
        {
          cout << "Are you constantly nervous?" << endl;
          cin >> choice;
          if(choice == 'Y')
          {
            rule_num = 60;
            clause_num = 4 * (rule_num / 10 - 1)+ 1;
            //Generalized Anxiety Disorder 
            return rule_num;
          }
          else
          {
            rule_num = 70;
            clause_num = 4 * (rule_num / 10 - 1)+ 1;
            //Panic Disorder with Agoraphobia
            return rule_num;
          }
        }
      }
    }
    else
    {
      cout << "Are you positive about life?" << endl;
      cin >> choice;
      if(choice == 'N')
      {
        rule_num = 80;
        clause_num = 4 * (rule_num / 10 - 1)+ 1;
        cout << "Do you question yourself?" << endl;
        cin >> choice;
        if(choice == 'Y')
        {
          rule_num = 90;
          clause_num = 4 * (rule_num / 10 - 1)+ 1;
          cout << "Does your family have a history of mental health disorders?" << endl;
          cin >> choice;
          if(choice == 'N')
          {
            rule_num = 100;
            clause_num = 4 * (rule_num / 10 - 1)+ 1;
            cout << "Do you hallucinate?" << endl;
            cin >> choice;
            if(choice == 'Y')
            {
              rule_num = 110;
              clause_num = 4 * (rule_num / 10 - 1)+ 1;
              //Schizo-affective Disorder
              return rule_num;
            }
            else
            {
              //reconsider
              rule_num = 250;
              clause_num = 4 * (rule_num / 10 - 1)+ 1;
              return rule_num;
            }
          }
          else
          {
            rule_num = 120;
            clause_num = 4 * (rule_num / 10 - 1)+ 1;
            cout << "Do you sleep for more than 10 hours?" << endl;
            cin >> choice;
            if(choice == 'Y')
            {
              rule_num = 130;
              clause_num = 4 * (rule_num / 10 - 1)+ 1;
              cout << "Have you felt consistantly sad for more than 2+ years?" << endl;
              cin >> choice;
              if(choice == 'Y')
              {
                rule_num = 140;
                clause_num = 4 * (rule_num / 10 - 1)+ 1;
                //Dysthymia
                return rule_num;
              }
              else
              {
                rule_num = 150;
                clause_num = 4 * (rule_num / 10 - 1)+ 1;
                //Major Depression Disorder
                return rule_num;
              }
            }
            else
            {
              rule_num = 160;
              clause_num = 4 * (rule_num / 10 - 1)+ 1;
               cout << "Do you have a reduced need for sleep?" << endl;
               cin >> choice;
               if(choice == 'Y')
               {
                 rule_num = 170;
                  clause_num = 4 * (rule_num / 10 - 1)+ 1;
                  cout << "Has mental health affected your relationships?" << endl;
                  cin >> choice;
                  if(choice == 'Y')
                  {
                    rule_num = 180;
                    clause_num = 4 * (rule_num / 10 - 1)+ 1;
                    cout << "Do you experience highs and lows?" << endl;
                    cin >> choice;
                    if(choice == 'Y')
                    {
                      rule_num = 190;
                      clause_num = 4 * (rule_num / 10 - 1)+ 1;
                      //Bipolar Disorder
                      return rule_num;
                    }
                    else
                    {
                      rule_num = 200;
                      clause_num = 4 * (rule_num / 10 - 1)+ 1;
                      // reconsider
                      return rule_num;
                    }
                  }
                  else
                  {
                      rule_num = 210;
                      clause_num = 4 * (rule_num / 10 - 1)+ 1;
                    //reconsider
                      return rule_num;
                  }
               }
               else
               {
                 rule_num = 220;
                 clause_num = 4 * (rule_num / 10 - 1)+ 1;
                // reconsider
                return rule_num;
               }
            }
          }
        }
        else
        {
          rule_num = 230;
          clause_num = 4 * (rule_num / 10 - 1)+ 1;
          //reconsider
          return rule_num;
        }
      }
      else
      {
        rule_num = 240;
        clause_num = 4 * (rule_num / 10 - 1)+ 1;
        //reconsider
        return rule_num;
      }
    }
  }
  else
  {
    //not qaulify 
    rule_num = 10;
    clause_num = 4 * (rule_num / 10 - 1)+ 1;
    return rule_num;
  }
}
// forward chaining function 
// convert to rules
// find treatments

// 1. Bipolar Disorder
//      SSRIs, Anticonvulsant, or Antipsychotic 
// 2. Schizophernia 
//      Antipsychotic or anti-tremor 
// 3. Schizo-affective Disorder
//      SSRIs, Anticonvulsant, or Antipsychotic
// 4. Major Depressive Disorder
//       SSRIs, Antidepressent, Antipsychotic or Anxiolytic
// 5. Panic Disorder with Agoraphobia 
//        Anxiolytic, SSRIs, Sedative
// 6. Dissociative Idenity Disorder
//        Talk therapy or psychotherapy 
// 7. Dysthymia 
//        SSRIs or antidepressent
// 8. Generalized Anexity Disorder 
//        SSRIs, Antidepressent, or Antipsychotic
//-----------------------------------------------
// 10 = not qualify 
// 20 = qualifies
// 40 = schizophrenia 
// 50 = Dissociative Identity Disorder
// 60 = Generalized Anexity Disorder
// 70 = Panic Disorder with Agoraphobia
// 110 = Schizo-affective Disorder
// 140 = Dysthymia
// 150 = Major Depressive Disorder
// 190 = Bipolar Disorder
// 200 - 250 = Reconsider(5)
void fwd_chain(int clause_num)
{
// FORMULA
// if user has x symptom(s) then user has x
  
//int rule_num = (((clause_num / 4)+1 ) * 10);
// RULE # = ((clause_num # / 4 ) + 1) * 10

  if(clause_num == 1)
  {
    //user does NOT qaulify 
    // rule 10 = clause 1
    int rule_num = (((clause_num / 4)+1 ) * 10);  
    cout << "The patient does not qaualify. " << endl;
    cout << "Therefore, we cannot recommend a treatment. Please try the test again. " << endl; 
  }
  if (clause_num == 5)
  {
    // user qaulifies 
    // rule 20 = clause 5
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient qaulifies. " << endl;
    cout << "Therefore, we will generate treatments. " << endl; 
  }
  if(clause_num == 13)
  {
    // user has schizophernia 
    // rule 40 = clause 13
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Schizophernia." << endl;
    cout << "We recommend the patient to start seeking treatment of Antipsychotic or anti-tremor."<< endl;
    
  }
  if(clause_num == 17)
  {
    // user has dissociate disorder 
    // rule 50 = clause 17
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Dissociate Identity Disorder." << endl;
    cout << "We recommend the patient to start seeking treatment of Talk Therapy or Psychotherapy."<< endl;
  }
  if(clause_num == 21)
  {
    // user has generalized anxiety disorder 
    // rule 60 = clause 21
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Generalized Anxiety Disorder." << endl;
    cout << "We recommend the patient to start seeking treatment of SSRIs, Antidepressent, or Antipsychotic."<< endl;
  }
  if(clause_num == 25)
  {
    // user has Panic disorder 
    // rule 70 = clause 25
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Panic Disorder with Agoraphobia." << endl;
    cout << "We recommend the patient to start seeking treatment of Anxiolytic, SSRIs, or Sedative."<< endl;
  }
  if(clause_num == 41)
  {
    // user has schizo-affective  
    // rule 110 = clause 41
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Schizo-affective Disorder." << endl;
    cout << "We recommend the patient to start seeking treatment of SSRIs, Anticonvulsant, or Antipsychotic."<< endl;
  }
  if(clause_num == 53)
  {
    // user has Dysthimia
    // rule 140 = clause 53
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Dysthymia." << endl;
    cout << "We recommend the patient to start seeking treatment of SSRIs or Antidepressents."<< endl;
  }
  if(clause_num == 57)
  {
    // user has depression 
    // rule 150 = clause 57
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Major Depression Disorder." << endl;
    cout << "We recommend the patient to start seeking treatment of SSRIs, Antidepressent, Antipsychotic or Anxiolytic"<< endl;
  }
  if(clause_num == 73)
  {
    // user has bipolar 
    // rule 190 = clause 73
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient has Bipolar Disorder." << endl;
    cout << "We recommend the patient to start seeking treatment of SSRIs, Anticonvulsant, or Antipsychotic"<< endl;
  }
  if(clause_num == 77)
  {
    // user has reconsider 
    // rule 200 = clause 77
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient does not have a position." << endl;
    cout << "Therefore, we cannot recommond a treatment. Please retake the test and reconsider your answers. " << endl;
  }
  if(clause_num == 81)
  {
    // user has reconsider 
    // rule 210 = clause 81
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient does not have a position." << endl;
    cout << "Therefore, we cannot recommond a treatment. Please retake the test and reconsider your answers. " << endl;
  }
  if(clause_num == 85)
  {
    // user has reconsider 
    // rule 220 = clause 85
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient does not have a position." << endl;
    cout << "Therefore, we cannot recommond a treatment. Please retake the test and reconsider your answers. " << endl;
  }
  if(clause_num == 89)
  {
    // user has reconsider 
    // rule 230 = clause 89
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient does not have a position." << endl;
    cout << "Therefore, we cannot recommond a treatment. Please retake the test and reconsider your answers. " << endl;
  }
  if(clause_num == 93)
  {
    // user has reconsider 
    // rule 240 = clause 93
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient does not have a position." << endl;
    cout << "Therefore, we cannot recommond a treatment. Please retake the test and reconsider your answers. " << endl;
  }
  if(clause_num == 97)
  {
    // user has reconsider 
    // rule 250 = clause 97
    int rule_num = (((clause_num / 4)+1 ) * 10);
    cout << "The patient does not have a position." << endl;
    cout << "Therefore, we cannot recommond a treatment. Please retake the test and reconsider your answers. " << endl;
  }
  return 0; 
}

  
  