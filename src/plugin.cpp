#include "plugin.h"
#include <KPluginFactory>
#include <KTextEditor/MainWindow>
#include <KMessageBox>
#include <QProcess>

K_PLUGIN_FACTORY_WITH_JSON(GitLogPluginFactory, "gitlogplugin.json", registerPlugin<GitLogPlugin>();)

GitLogPlugin::GitLogPlugin(QObject *parent)
: KTextEditor::Plugin(parent)
{
}

GitLogPlugin::~GitLogPlugin()
{
}

QObject *GitLogPlugin::create(KTextEditor::MainWindow *mainWindow)
{
  Q_UNUSED(mainWindow)
  QString log;
  QProcess process;
  process.start("git log", QStringList() << "--pretty=format:%h - %s");
  if (process.waitForFinished()) {
    log = process.readAllStandardOutput();
  }
  KMessageBox::information(nullptr, log, "Git Log");
  return nullptr;
}

#include "plugin.moc"
