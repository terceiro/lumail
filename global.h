/**
 * global.h - Singleton interface to store global data
 */

#ifndef _global_h_
#define _global_h_ 1

#include <vector>
#include <string>
#include "maildir.h"
#include "message.h"

/**
 * A singleton class to store global data.
 *
 */
class CGlobal
{
 public:

  /**
   * Get access to the singleton instance.
   */
  static CGlobal *Instance();

  /**
   * Get/Set the current lumail-mode: index/maildir/message
   */
  void set_mode(std::string * mode);
  std::string * get_mode();

  /**
   * Get/Set the maildir-prefix, which is where we find Maildir-folders beneath.
   */
  void set_maildir_prefix(std::string * prefix);
  std::string * get_maildir_prefix();

  /**
   * Get/Set the index-format.
   */
  void set_index_format(std::string * fmt);
  std::string * get_index_format();

  /**
   * Get all folders.
   */
  std::vector < CMaildir > get_all_folders();

  /**
   * Get all folders which match the current mode: new/all/pattern
   */
  std::vector < CMaildir > get_folders();

  /**
   * Get all selected folders.
   */
  std::vector < std::string > get_selected_folders();

  /**
   * Get all messages from the currently-selected folders.
   */
  std::vector < CMessage > get_messages();

  /**
   * Remove all selected folders.
   */
  void unset_folders();

  /**
   * Add a folder to the selected set.
   */
  void add_folder(std::string path);

  /**
   * Remove a folder from the selected set.
   */
  bool remove_folder(std::string path);

  /**
   * Get/Set the maildir-display limit: new/all/pattern
   */
  std::string * get_maildir_limit();
  void set_maildir_limit(std::string * limit);

  /**
   * Get/set the selected folder, i.e. the one with the highlight.
   */
  int get_selected_folder() {
    return m_cur_folder;
  }
  void set_selected_folder(int offset) {
    m_cur_folder = offset;
  }

  /**
   * Get/Set the selected message.  Not used.
   */
  int get_selected_message() {
    return m_cur_message;
  }
  void set_selected_message(int offset) {
    m_cur_message = offset;
  }

 protected:

  /**
   * Protected functions to allow our singleton implementation.
   */
  CGlobal();
  CGlobal(const CGlobal &);
  CGlobal & operator=(const CGlobal &);

 private:

  /**
   * The single instance of this class.
   */
  static CGlobal *pinstance;

  /**
   * The selected folder.
   */
  int m_cur_folder;

  /**
   * The selected message.
   */
  int m_cur_message;

  /**
   * The mode the client is in: index, maildir, or message.
   */
  std::string * m_mode;

  /**
   * The limit-string for the display of folders.
   */
  std::string * m_maildir_limit;

  /**
   * The maildir-prefix.
   */
  std::string * m_maildir_prefix;

  /**
   * Currently selected folders.
   */
  std::vector < std::string > m_selected_folders;

  /**
   * The index-format string.
   */
  std::string * m_index_format;

};

#endif /* _global_h_ */
