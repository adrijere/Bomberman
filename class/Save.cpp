//
// Save.cpp for save in /home/hure_s/tek2/rendu/cpp_bomberman/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon May 18 17:53:28 2015 simon hure
// Last update Mon May 18 18:04:33 2015 simon hure
//

Save::Save()
{
  //init state and file counter to 1
}

Save::~Save()
{
  //check for tmp file that should be deleted
}

void	Save::save()
{
  //check state
  //get file number
  //write to tmp file
  //use specific function for parts such as header,maps...
  //include time reference to each save
  //encrypt and write to definive file
  //encrypt with +12 rotone
}

void	Save::get_save()
{
  //read file by incresing number
  //if found write and decrypt data to tmp
  //decrypt with -12 rotone
  //add element to list of data
  //class by time (if possible)
  //delete tmp file after use
  //else search for next file if 5 time in a row no valid file exits
}

void	Save::score()
{
  //get highscore at begining and store them in list
  //store score and events in file
  //need encryption too
}
