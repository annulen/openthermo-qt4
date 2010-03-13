TEMPLATE = subdirs
SUBDIRS = common application extension 
application.depends = common
extension.depends = common
