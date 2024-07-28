#ifndef GITLOGPLUGIN_H
#define GITLOGPLUGIN_H

#include <KTextEditor/Plugin>

class GitLogPlugin : public KTextEditor::Plugin
{
  Q_OBJECT

public:
  explicit GitLogPlugin(QObject *parent = nullptr, const QList<QVariant> & = QList<QVariant>());
  ~GitLogPlugin() override;

  QObject *create(KTextEditor::MainWindow *mainWindow) override;
};

#endif // GITLOGPLUGIN_H
