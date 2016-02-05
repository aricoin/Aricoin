include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = aricoin-qt
noinst_LIBRARIES = libaricoinqt.a
SUBDIRS = . $(BUILD_TEST_QT)
DIST_SUBDIRS = . test

# aricoin qt core #
QT_TS = \
  locale/aricoin_ach.ts \
  locale/aricoin_af_ZA.ts \
  locale/aricoin_ar.ts \
  locale/aricoin_be_BY.ts \
  locale/aricoin_bg.ts \
  locale/aricoin_bs.ts \
  locale/aricoin_ca_ES.ts \
  locale/aricoin_ca.ts \
  locale/aricoin_ca@valencia.ts \
  locale/aricoin_cmn.ts \
  locale/aricoin_cs.ts \
  locale/aricoin_cy.ts \
  locale/aricoin_da.ts \
  locale/aricoin_de_AT.ts \
  locale/aricoin_de.ts \
  locale/aricoin_el_GR.ts \
  locale/aricoin_en.ts \
  locale/aricoin_eo.ts \
  locale/aricoin_es_CL.ts \
  locale/aricoin_es_DO.ts \
  locale/aricoin_es_MX.ts \
  locale/aricoin_es.ts \
  locale/aricoin_es_UY.ts \
  locale/aricoin_et.ts \
  locale/aricoin_eu_ES.ts \
  locale/aricoin_fa_IR.ts \
  locale/aricoin_fa.ts \
  locale/aricoin_fi.ts \
  locale/aricoin_fr_CA.ts \
  locale/aricoin_fr.ts \
  locale/aricoin_gl.ts \
  locale/aricoin_gu_IN.ts \
  locale/aricoin_he.ts \
  locale/aricoin_hi_IN.ts \
  locale/aricoin_hr.ts \
  locale/aricoin_hu.ts \
  locale/aricoin_id_ID.ts \
  locale/aricoin_it.ts \
  locale/aricoin_ja.ts \
  locale/aricoin_ka.ts \
  locale/aricoin_kk_KZ.ts \
  locale/aricoin_ko_KR.ts \
  locale/aricoin_ky.ts \
  locale/aricoin_la.ts \
  locale/aricoin_lt.ts \
  locale/aricoin_lv_LV.ts \
  locale/aricoin_ms_MY.ts \
  locale/aricoin_nb.ts \
  locale/aricoin_nl.ts \
  locale/aricoin_pam.ts \
  locale/aricoin_pl.ts \
  locale/aricoin_pt_BR.ts \
  locale/aricoin_pt_PT.ts \
  locale/aricoin_ro_RO.ts \
  locale/aricoin_ru.ts \
  locale/aricoin_sah.ts \
  locale/aricoin_sk.ts \
  locale/aricoin_sl_SI.ts \
  locale/aricoin_sq.ts \
  locale/aricoin_sr.ts \
  locale/aricoin_sv.ts \
  locale/aricoin_th_TH.ts \
  locale/aricoin_tr.ts \
  locale/aricoin_uk.ts \
  locale/aricoin_ur_PK.ts \
  locale/aricoin_uz@Cyrl.ts \
  locale/aricoin_vi.ts \
  locale/aricoin_vi_VN.ts \
  locale/aricoin_zh_CN.ts \
  locale/aricoin_zh_HK.ts \
  locale/aricoin_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/paperwalletdialog.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_aricoinaddressvalidator.cpp \
  moc_aricoinamountfield.cpp \
  moc_aricoingui.cpp \
  moc_aricoinunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_verticallabel.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp

ARICOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  aricoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_aricoin.cpp
QT_QRC = aricoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

ARICOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  aricoinaddressvalidator.h \
  aricoinamountfield.h \
  aricoingui.h \
  aricoinunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  verticallabel.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h \
  winshutdownmonitor.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/aricoin.ico \
  res/icons/aricoin.png \
  res/icons/aricoin_testnet.ico \
  res/icons/aricoin_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/print.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png
  
#RES_FONTS = \
#  res/fonts/ComicNeue-Bold.ttf \
#  res/fonts/ComicNeue-Bold-Oblique.ttf \
#  res/fonts/ComicNeue-Light.ttf \
#  res/fonts/ComicNeue-Light-Oblique.ttf \
#  res/fonts/ComicNeue-Regular.ttf \
#  res/fonts/ComicNeue-Regular-Oblique.ttf

ARICOIN_QT_CPP = \
  aricoin.cpp \
  aricoinaddressvalidator.cpp \
  aricoinamountfield.cpp \
  aricoingui.cpp \
  aricoinunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp \
  verticallabel.cpp \
  winshutdownmonitor.cpp

if ENABLE_WALLET
ARICOIN_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  paymentserver.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsdialog.cpp \
  sendcoinsentry.cpp \
  signverifymessagedialog.cpp \
  transactiondesc.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactionrecord.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  verticallabel.cpp \
  walletframe.cpp \
  walletmodel.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png \
  res/images/paper_wallet.png \
  res/images/wallet_bgcoin.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

ARICOIN_RC = res/aricoin-qt-res.rc

libaricoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libaricoinqt_a_SOURCES = $(ARICOIN_QT_CPP) $(ARICOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(RES_FONTS)

nodist_libaricoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libaricoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# aricoin-qt binary #
aricoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
aricoin_qt_SOURCES = aricoin.cpp
if TARGET_DARWIN
  aricoin_qt_SOURCES += $(ARICOIN_MM)
endif
if TARGET_WINDOWS
  aricoin_qt_SOURCES += $(ARICOIN_RC)
endif
aricoin_qt_LDADD = libaricoinqt.a $(LIBARICOIN_SERVER)
if ENABLE_WALLET
aricoin_qt_LDADD += $(LIBARICOIN_WALLET) $(LIBARICOIN_SERVER_WALLET)
endif
aricoin_qt_LDADD += $(LIBARICOIN_CLI) $(LIBARICOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
aricoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

aricoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/aricoinstrings.cpp

translate: aricoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(ARICOIN_QT_CPP) $(ARICOIN_QT_H) $(ARICOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/aricoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(RES_FONTS) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name aricoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -e '/^\*\*.*Created:/d' $@ > $@.n && mv $@{.n,}
	$(SED) -e '/^\*\*.*by:/d' $@  > $@.n && mv $@{.n,}

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
