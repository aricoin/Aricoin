include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_srcdir)/src/qt \
  -I$(top_builddir)/src/qt \
  $(PROTOBUF_CFLAGS) \
    $(QR_CFLAGS)
bin_PROGRAMS = test_aricoin-qt
TESTS = test_aricoin-qt

TEST_QT_MOC_CPP = \
  moc_aricoinunitstests.cpp \
  moc_uritests.cpp

if ENABLE_WALLET
TEST_QT_MOC_CPP += moc_paymentservertests.cpp
endif

TEST_QT_H = \
  aricoinunitstests.h \
  uritests.h \
  paymentrequestdata.h \
  paymentservertests.h

BUILT_SOURCES = $(TEST_QT_MOC_CPP)

test_aricoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) $(QT_TEST_INCLUDES)

test_aricoin_qt_SOURCES = \
  aricoinunitstests.cpp \
  test_main.cpp \
  uritests.cpp \
  $(TEST_QT_H)
if ENABLE_WALLET
test_aricoin_qt_SOURCES += \
  paymentservertests.cpp
endif

nodist_test_aricoin_qt_SOURCES = $(TEST_QT_MOC_CPP)

test_aricoin_qt_LDADD = $(LIBARICOINQT)
if ENABLE_WALLET
test_aricoin_qt_LDADD += $(LIBARICOIN_WALLET) $(LIBARICOIN_SERVER_WALLET)
endif
test_aricoin_qt_LDADD += $(LIBARICOIN_SERVER)
if ENABLE_WALLET
test_aricoin_qt_LDADD += $(LIBARICOIN_SERVER_WALLET)
endif
test_aricoin_qt_LDADD += $(LIBARICOIN_CLI) $(LIBARICOIN_COMMON) \
  ${RPCWALLET} $(LIBLEVELDB) \
  $(LIBMEMENV) $(BOOST_LIBS) $(QT_DBUS_LIBS) $(QT_TEST_LIBS) $(QT_LIBS) \
  $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
test_aricoin_qt_LDFLAGS = $(QT_LDFLAGS)

CLEANFILES = $(BUILT_SOURCES) *.gcda *.gcno
